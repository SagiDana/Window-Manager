X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

LIBS = -L${X11LIB} -lX11 -lm -lXinerama
INCS = -I${X11INC}

CC = cc

LDFLAGS = ${LIBS}
CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS}

SRC = wm.c common.c workspace.c window.c list.c tree.c arrange.c point.c monitor.c arrange_tree.c arrange_default.c

OBJ = ${SRC:.c=.o}

all: wm options

options:
	@echo wm build options:
	@echo "CFLAGS	=${CFLAGS}"
	@echo "LDFLAGS	=${LDFLAGS}"
	@echo "CC	=${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

wm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean: 
	rm wm *.o
