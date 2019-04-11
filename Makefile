CC     = gcc
CFLAGS_WARN_OK = -Wall -Wno-unused-variable -I/usr/include/ImageMagick -g3
CFLAGS = $(CFLAGS_WARN_OK) -Werror 
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer -Wno-format-security

LIBS = -lpthread
ASAN_LIBS = -static-libasan

MAGICK_FLAGS = `pkg-config --cflags MagickCore`
MAGICK_LIBS = `pkg-config --libs MagickCore`

mj: minifyjpeg.c magickminify.o
	$(CC) -o $@ $(CFLAGS) $(ASAN_FLAGS) $^ $(LIBS) $(MAGICK_LIBS) $(ASAN_LIBS) $(MAGICK_FLAGS)

all: mj

#### Cleanup ####
clean:
	rm -f mj

