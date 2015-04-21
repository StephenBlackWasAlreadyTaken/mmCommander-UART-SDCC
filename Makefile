CC=sdcc
CFLAGS=-Iinclude
CFLAGSold=--no-pack-iram $(CF)
LFLAGS=--xram-loc 0xF000 

apps = cc1111rf.rel global.rel
libsvcom = $(apps) cc1111_vcom.rel cc1111_vcomdesc.rel
libsusb  = $(apps) cc1111usb.rel cc1111usbdebug.rel
#srcs = $(libs,.rel=.c) 


all: chronosapplication.hex
donfw: donapplication.hex
immefw: immeapplication.hex
testrecv: testrecvapplication.hex
testxmit: testxmitapplication.hex

%.rel : %.c
	$(CC) $(CFLAGS) -c $<

chronosapplication.hex: application.c $(libsusb)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsusb) -DCHRONOSDONGLE
	packihx <application.ihx >bins/application.hex

donapplication.hex: application.c $(libsusb)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsusb) -DDONSDONGLES
	packihx <application.ihx >bins/application.hex

immeapplication.hex: application.c $(libsusb)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsusb) -DIMMEDONGLE
	packihx <application.ihx >bins/application.hex

testxmitusb.hex: application.c $(libsusb)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsusb) -DCHRONOSDONGLE -DTRANSMIT_TEST 
	packihx <application.ihx >bins/testxmit.hex

testrecvusb.hex: application.c $(libsusb)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsusb) -DCHRONOSDONGLE -DRECEIVE_TEST
	packihx <application.ihx >bins/testrecv.hex

testxmitapplication.hex: application.c $(libsvcom)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsvcom) -DCHRONOSDONGLE -DVIRTUAL_COM -DTRANSMIT_TEST 
	packihx <application.ihx >bins/testxmit.hex

testrecvapplication.hex: application.c $(libsvcom)
	sdcc $(CFLAGS) $(LFLAGS) application.c $(libsvcom) -DCHRONOSDONGLE -DVIRTUAL_COM -DRECEIVE_TEST
	packihx <application.ihx >bins/testrecv.hex


installchronosfw: chronosapplication.hex
	goodfet.cc erase
	goodfet.cc flash bins/application.hex
	goodfet.cc info

installdonfw: donapplication.hex
	goodfet.cc erase
	goodfet.cc flash bins/application.hex
	goodfet.cc info

installimmefw: immeapplication.hex
	goodfet.cc erase
	goodfet.cc flash bins/application.hex
	goodfet.cc info

installtestrecvusbfw: testrecvusb.hex
	goodfet.cc erase
	goodfet.cc flash bins/testrecv.hex
	goodfet.cc info

installtestxmitusbfw: testxmitusb.hex
	goodfet.cc erase
	goodfet.cc flash bins/testxmit.hex
	goodfet.cc info

installtestrecvfw: testrecvapplication.hex
	goodfet.cc erase
	goodfet.cc flash bins/testrecv.hex
	goodfet.cc info

installtestxmitfw: testxmitapplication.hex
	goodfet.cc erase
	goodfet.cc flash bins/testxmit.hex
	goodfet.cc info


verify: chronosapplication.hex
	goodfet.cc verify bins/application.hex

clean:
	rm -f *.ihx *.rel *.hex *.sym *.asm *.lst *.lnk *.map *.mem *.rst
