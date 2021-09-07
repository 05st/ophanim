all: run

kernel.bin: entry.o kernel.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

entry.o: kernel/entry.asm
	nasm $< -f elf -o $@

kernel.o: kernel/kernel.c
	i686-elf-gcc -ffreestanding -c $< -o $@

boot.bin: boot/boot.asm
	nasm $< -f bin -o $@

os.bin: boot.bin kernel.bin
	cat $^ > $@

run: os.bin
	qemu-system-x86_64 -drive format=raw,if=floppy,file=$<

clean:
	rm *.bin *.o

