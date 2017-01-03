#
# Makefile for Emscripten
#

CC = emcc
AR = emar
EMTERPRET = -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1
CFLAGS = -O0 -Wall $(EMTERPRET)
LIBS = 
PREFIX = ../
SUFFIX = .js

all_cflags = $(CFLAGS)
objs = bme.o bme_gfx.o bme_io.o bme_win.o bme_kbd.o bme_mou.o		\
bme_joy.o bme_map.o bme_txt.o bme_snd.o bme_mod.o bme_xm.o bme_s3m.o	\
bme_raw.o bme_wav.o bme_smp.o bme_tbl.o
picobjs = $(objs:.o=.pic.o)
so = $(PREFIX)libbme.so.0

all: $(PREFIX)libbme.a $(so) $(PREFIX)bmeconv$(SUFFIX) $(PREFIX)datafile$(SUFFIX) $(PREFIX)dat2inc$(SUFFIX) $(PREFIX)bmeplay$(SUFFIX)
.PHONY: all

clean: linkclean
	-rm -f *.o
	-rm -f mapdata.c
#	-rm -f mapedit.dat
#	-rm -f *.spr
.PHONY: clean

linkclean:
	-rm -f $(PREFIX)libbme.a
	-rm -f $(so)
	-rm -f $(PREFIX)bmeconv$(SUFFIX)
	-rm -f $(PREFIX)bmeplay$(SUFFIX)
	-rm -f $(PREFIX)dat2inc$(SUFFIX)
	-rm -f $(PREFIX)datafile$(SUFFIX)
	-rm -f $(PREFIX)infedit$(SUFFIX)
	-rm -f $(PREFIX)mapedit$(SUFFIX)
.PHONY: linkclean

$(PREFIX)libbme.a: $(objs)
	$(AR) rs $@ $^

%.o: %.c
	$(CC) -c $(all_cflags) -o $@ $<

$(so): versions $(picobjs)
	$(CC) -shared -o $@ -Wl,--version-script=versions,-soname=$(so) $(picobjs) $(LIBS)

%.pic.o: %.c
	$(CC) -c -fPIC $(all_cflags) -o $@ $<

mapdata.c: mapedit.dat $(PREFIX)dat2inc
	$(PREFIX)dat2inc $< $@

mapedit.dat: mapedit.seq $(PREFIX)datafile fonts.spr editor.spr
	$(PREFIX)datafile $@ $<


$(PREFIX)mapedit$(SUFFIX): mapedit.o fileio.o cfgfile.o mapdata.o $(PREFIX)libbme.a 
	$(CC) -o $@ $^ $(LIBS)

$(PREFIX)infedit$(SUFFIX): infedit.o fileio.o cfgfile.o mapdata.o $(PREFIX)libbme.a
	$(CC) -o $@ $^ $(LIBS)

$(PREFIX)bmeplay$(SUFFIX): bmeplay.o $(PREFIX)libbme.a
	$(CC) -o $@ $^ $(LIBS)

$(PREFIX)datafile$(SUFFIX): datafile.o fileio.o
	$(CC) -o $@ $^

$(PREFIX)bmeconv$(SUFFIX): bmeconv.o fileio.o
	$(CC) -o $@ $^

$(PREFIX)dat2inc$(SUFFIX): dat2inc.o
	$(CC) -o $@ $^
