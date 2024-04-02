
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp \
        structures/nodes/NodeAVL.h \
        structures/nodes/SimpleNode.h \
        structures/nodes/DoubleNode.h \
        structures/linkedList/LinkedList.h \
        directory/Group.cpp \
        directory/Group.h \
        structures/Hash/TableLL.h \
        structures/Hash/Function.h \
        directory/Field.h \
        structures/doubleLinkedList/DoubleLinkedList.h \
        structures/tree/TreeAVL.h \
        utils/Export/DataManager.cpp \
        utils/Export/DataManager.h \
        utils/Graphs/GraphvizManager.cpp \
        utils/Graphs/GraphvizManager.h \
        structures/doubleLinkedList/DoubleListAVL.h \
        structures/tree/TreeInteger.h \
        structures/tree/TreeString.h \
        structures/tree/TreeChar.h
	$(CC) $(CFLAGS) -c $< -o $@

structures/nodes/NodeAVL.o: structures/nodes/NodeAVL.h
	$(CC) $(CFLAGS) -c structures/nodes/NodeAVL.o structures/nodes/NodeAVL.h

structures/nodes/SimpleNode.o: structures/nodes/SimpleNode.h
	$(CC) $(CFLAGS) -c structures/nodes/SimpleNode.o structures/nodes/SimpleNode.h

structures/nodes/DoubleNode.o: structures/nodes/DoubleNode.h
	$(CC) $(CFLAGS) -c structures/nodes/DoubleNode.o structures/nodes/DoubleNode.h

structures/linkedList/LinkedList.o: structures/linkedList/LinkedList.h
	$(CC) $(CFLAGS) -c structures/linkedList/LinkedList.o structures/linkedList/LinkedList.h

directory/Group.o: directory/Group.cpp directory/Group.h
	$(CC) $(CFLAGS) -c directory/Group.o directory/Group.cpp directory/Group.h

structures/Hash/TableLL.o: "structures/Hash/TableLL.h"
	$(CC) $(CFLAGS) -c structures/Hash/TableLL.o structures/Hash/TableLL.h

structures/Hash/Function.o: "structures/Hash/Function.h"
	$(CC) $(CFLAGS) -c structures/Hash/Function.o structures/Hash/Function.h

directory/Field.o: directory/Field.h
	$(CC) $(CFLAGS) -c directory/Field.o directory/Field.h

structures/doubleLinkedList/DoubleLinkedList.o: structures/doubleLinkedList/DoubleLinkedList.h
	$(CC) $(CFLAGS) -c structures/doubleLinkedList/DoubleLinkedList.o structures/doubleLinkedList/DoubleLinkedList.h

structures/tree/TreeAVL.o: structures/tree/TreeAVL.h
	$(CC) $(CFLAGS) -c structures/tree/TreeAVL.o structures/tree/TreeAVL.h

utils/Export/DataManager.o: utils/Export/DataManager.cpp utils/Export/DataManager.h
	$(CC) $(CFLAGS) -c utils/Export/DataManager.o utils/Export/DataManager.cpp utils/Export/DataManager.h

utils/Graphs/GraphvizManager.o: utils/Graphs/GraphvizManager.cpp utils/Graphs/GraphvizManager.h
	$(CC) $(CFLAGS) -c utils/Graphs/GraphvizManager.o utils/Graphs/GraphvizManager.cpp utils/Graphs/GraphvizManager.h

structures/doubleLinkedList/DoubleListAVL.o: structures/doubleLinkedList/DoubleListAVL.h
	$(CC) $(CFLAGS) -c structures/doubleLinkedList/DoubleListAVL.o structures/doubleLinkedList/DoubleListAVL.h

structures/tree/TreeInteger.o: structures/tree/TreeInteger.h
	$(CC) $(CFLAGS) -c structures/tree/TreeInteger.o structures/tree/TreeInteger.h

structures/tree/TreeString.o: structures/tree/TreeString.h
	$(CC) $(CFLAGS) -c structures/tree/TreeString.o structures/tree/TreeString.h

structures/tree/TreeChar.o: structures/tree/TreeChar.h
	$(CC) $(CFLAGS) -c structures/tree/TreeChar.o structures/tree/TreeChar.h

all: $(TARGET)

# Limpiar
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean
