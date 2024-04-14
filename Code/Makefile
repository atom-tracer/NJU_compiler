# GNU make手册：http://www.gnu.org/software/make/manual/make.html
# ************ 遇到不明白的地方请google以及阅读手册 *************

# 编译器设定和编译选项
CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -std=c99

# 编译目标：src目录下的所有.c文件
CFILES = $(shell find ./ -name "*.c")
OBJS = $(CFILES:.c=.o)
LFILE = $(shell find ./ -name "*.l")
YFILE = $(shell find ./ -name "*.y")
LFC = $(shell find ./ -name "*.l" | sed s/[^/]*\\.l/lex.yy.c/)
YFC = $(shell find ./ -name "*.y" | sed s/[^/]*\\.y/syntax.tab.c/)
LFO = $(LFC:.c=.o)
YFO = $(YFC:.c=.o)

parser: syntax $(filter-out $(LFO),$(OBJS))
	$(CC) -o parser $(filter-out $(LFO),$(OBJS)) -lfl -ly

syntax: lexical syntax-c
	$(CC) -c $(YFC) -o $(YFO)

lexical: $(LFILE)
	$(FLEX) -o $(LFC) $(LFILE)

syntax-c: $(YFILE)
	$(BISON) -o $(YFC) -d -v $(YFILE)

-include $(patsubst %.o, %.d, $(OBJS))

# 定义的一些伪目标
.PHONY: clean test
test:

	./parser ../Test/test_1/inputs/C-1.cmm > ../Test/test_1/myoutput/C-1.txt || true
	diff ../Test/test_1/myoutput/C-1.txt ../Test/test_1/expects/C-1.exp > ../Test/test_1/myoutput/C-1_diff.txt || true

	./parser ../Test/test_1/inputs/C-2.cmm > ../Test/test_1/myoutput/C-2.txt || true
	diff ../Test/test_1/myoutput/C-2.txt ../Test/test_1/expects/C-2.exp > ../Test/test_1/myoutput/C-2_diff.txt || true

	./parser ../Test/test_1/inputs/D-1.cmm > ../Test/test_1/myoutput/D-1.txt || true
	diff ../Test/test_1/myoutput/D-1.txt ../Test/test_1/expects/D-1.exp > ../Test/test_1/myoutput/D-1_diff.txt || true

	./parser ../Test/test_1/inputs/D-2.cmm > ../Test/test_1/myoutput/D-2.txt || true
	diff ../Test/test_1/myoutput/D-2.txt ../Test/test_1/expects/D-2.exp > ../Test/test_1/myoutput/D-2_diff.txt || true

	./parser ../Test/test_1/inputs/D-3.cmm > ../Test/test_1/myoutput/D-3.txt || true
	diff ../Test/test_1/myoutput/D-3.txt ../Test/test_1/expects/D-3.exp > ../Test/test_1/myoutput/D-3_diff.txt || true

	./parser ../Test/test_1/inputs/E3-1.cmm > ../Test/test_1/myoutput/E3-1.txt || true
	diff ../Test/test_1/myoutput/E3-1.txt ../Test/test_1/expects/E3-1.exp > ../Test/test_1/myoutput/E3-1_diff.txt || true

	./parser ../Test/test_1/inputs/myinput.cmm > ../Test/test_1/myoutput/myinput.txt || true

clean:
	rm -f parser lex.yy.c syntax.tab.c syntax.tab.h syntax.output
	rm -f $(OBJS) $(OBJS:.o=.d)
	rm -f $(LFC) $(YFC) $(YFC:.c=.h)
	rm -f *~
