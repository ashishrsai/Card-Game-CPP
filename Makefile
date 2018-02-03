# default target compiles and links everything
# has only dependencies, but no recipie
# compile and link
CC = g++

CPPFLAGS = -ggdb
TARGET = main
TARGET_G = cardGame
TARGET_D = deckCard
TARGET_DP = deckProt
TARGET_C = card
all: $(TARGET)

$(TARGET): $(TARGET).cpp $(TARGET_G).cpp $(TARGET_G).h $(TARGET_D).cpp $(TARGET_D).h $(TARGET_DP).cpp $(TARGET_DP).h $(TARGET_C).cpp $(TARGET_C).h
	$(CC) $(CPPFLAGS) -o $(TARGET) $(TARGET).cpp $(TARGET_G).cpp $(TARGET_D).cpp $(TARGET_DP).cpp $(TARGET_C).cpp


$(TARGET_C).o: $(TARGET_C).cpp $(TARGET_C).h 
	$(CC) $(CPPFLAGS) -c $(TARGET_C).cpp

$(TARGET_DP).o: $(TARGET_DP).cpp $(TARGET_DP).h 
	$(CC) $(CPPFLAGS) -c $(TARGET_DP).cpp 

$(TARGET_D).o: $(TARGET_D).cpp $(TARGET_D).h 
	$(CC) $(CPPFLAGS) -c $(TARGET_D).cpp 

$(TARGET_G).o: $(TARGET_G).cpp $(TARGET_G).h 
	$(CC) $(CPPFLAGS) -c $(TARGET_G).cpp 

main.o: $(TARGET).cpp 
	$(CC) $(CPPFLAGS) -c $(TARGET).cpp 

clean:
	$(RM) *.o *.~ $(TARGET)
