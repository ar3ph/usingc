OBJECTS=
CFLAGS= `pkg-config --cflags --libs glib-2.0` -I$(HOME)/opt/share/include -g -Wall -O0 -std=gnu11 -fprofile-arcs -ftest-coverage
LDLIBS= `pkg-config --libs glib-2.0` -L$(HOME)/opt/share/lib -lglib-2.0 -lgslcblas -lm -Wl,-R$(HOME)/opt/share/lib
CC=gcc


$(P): $(OBJECTS)
