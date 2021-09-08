C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h lib/*.h)

OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}

CC = /usr/local/cross/bin/i686-elf-gcc

CFLAGS = -ffreestanding -m32

os.bin: boot/boot.bin kernel.bin
	cat $^ > $@

kernel.bin: kernel/entry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

run: os.bin
	qemu-system-x86_64 -drive format=raw,if=floppy,file=$<

clean:
	rm -rf *.bin *.o
	rm -rf kernel/*.o drivers/*.o boot/*.bin cpu/*.o libc/*.o

