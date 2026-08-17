C_FLAGS = -g -Wall

all: image_editor

image.o: image.c image.h
	gcc $(C_FLAGS) -c image.c

trans_image.o: trans_image.c trans_image.h
	gcc $(C_FLAGS) -c trans_image.c

main_images.o: main_images.c image.h trans_image.h
	gcc $(C_FLAGS) -c main_images.c

image_editor: main_images.o image.o trans_image.o
	gcc $(C_FLAGS) -o image_editor main_images.o image.o trans_image.o

clean:
	rm -f *.o image_editor
