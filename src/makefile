CC = emcc
EMTERPRET = -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1
CFLAGS = -Wall $(EMTERPRET)
BMECONV = echo BMECONV does not appear to work under NodeJS. ignoring... You could try running this command manually to see if it works: node ../bme/bmeconv.js
LIBS = -L../bme -lbme -lm
SUFFIX = .html

all: ../missions/original.blk ../missions/test.blk ../data/bofh.pal	\
../data/splash.pal ../data/splash.raw ../data/title.spr			\
../data/player.spr ../data/weapon.spr ../data/machine.spr		\
../data/fistman.spr ../data/gunman.spr ../data/shotgman.spr		\
../data/uziman.spr ../data/tech.spr ../data/closet.spr			\
../data/leader.spr ../data/sadist.spr ../data/bigfnt.spr		\
../data/smallfnt.spr ../data/blackfnt.spr ../data/editor.spr ../bofh$(SUFFIX)	\
../bofhedit$(SUFFIX)
.PHONY: all

../bofh$(SUFFIX): actor.o bofh.o bomb.o enemy.o hiscore.o init.o sincos.o
	$(CC) $^ $(LIBS) $(EMTERPRET) -o $@ --preload-file ../data --preload-file ../missions --preload-file ../bofh.cfg@bofh.cfg

../bofhedit$(SUFFIX): bofhedit.o endian.o
	$(CC) $^ $(LIBS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

../missions/original.blk: bofhblk.lbm
	$(BMECONV) -b -t255 -r254 -h253 $< $@

../missions/test.blk: bofhblk.lbm
	$(BMECONV) -b -t255 -r254 -h253 $< $@

../data/bofh.pal: bofhblk.lbm
	$(BMECONV) -p $< $@

../data/%.pal: %.lbm
	$(BMECONV) -p $< $@

../data/%.raw: %.lbm
	$(BMECONV) -n $< $@

../data/%.spr: %.lbm
	$(BMECONV) -s -t255 -r254 -h253 $< $@

clean:
	-rm -f ../bofh$(SUFFIX) ../bofhedit$(SUFFIX) *.o 
#	-rm -f ../missions/original.blk ../missions/test.blk
#	-rm -f ../data/*.pal ../data/*.raw ../data/*.spr
.PHONY: clean
