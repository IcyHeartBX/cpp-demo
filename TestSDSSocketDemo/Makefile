CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		src/TestMain.o \
			src/CSckFactoryImpl1.o \
			src/CSckFactoryImpl2.o \
			src/des.o \
			src/CHwEncDesImpl.o 

LIBS =

INCLUDE = -I ./src

TARGET =	bin/TestSDSSocketDemo

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS) $(INCLUDE)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
