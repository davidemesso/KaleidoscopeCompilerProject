.PHONY: clean all

all: kfe

kfe: driver.o parser.o scanner.o kfe.o ifExprAST.o seqAST.o functionAST.o prototypeAST.o exprAST.o numberExprAST.o variableExprAST.o binaryExprAST.o unaryExprAST.o callExprAST.o forExprAST.o printAST.o varExprAST.o whileExprAST.o
	clang++ -o kfe driver.o parser.o scanner.o kfe.o ifExprAST.o seqAST.o functionAST.o exprAST.o numberExprAST.o prototypeAST.o variableExprAST.o binaryExprAST.o unaryExprAST.o callExprAST.o forExprAST.o printAST.o varExprAST.o whileExprAST.o `llvm-config --cxxflags --ldflags --libs --libfiles --system-libs` 

kfe.o: kfe.cc driver.hh ./AST/Utils/LogError.hh
	clang++ -c kfe.cc -I/usr/lib/llvm-11/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
	
parser.o: parser.cc
	clang++ -c parser.cc -I/usr/lib/llvm-11/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
	
scanner.o: scanner.cc parser.hh
	clang++ -c scanner.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
driver.o: driver.cc parser.hh driver.hh
	clang++ -c driver.cc -I/usr/lib/llvm-11/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 

ifExprAST.o: ./AST/IfExprAST.cc ./AST/IfExprAST.hh 
	clang++ -c ./AST/IfExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
seqAST.o: ./AST/SeqAST.cc ./AST/SeqAST.hh 
	clang++ -c ./AST/SeqAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
prototypeAST.o: ./AST/PrototypeAST.cc ./AST/PrototypeAST.hh 
	clang++ -c ./AST/PrototypeAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 

functionAST.o: ./AST/FunctionAST.cc ./AST/FunctionAST.hh 
	clang++ -c ./AST/FunctionAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
exprAST.o: ./AST/ExprAST.cc ./AST/ExprAST.hh 
	clang++ -c ./AST/ExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
numberExprAST.o: ./AST/NumberExprAST.cc ./AST/NumberExprAST.hh 
	clang++ -c ./AST/NumberExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
variableExprAST.o: ./AST/VariableExprAST.cc ./AST/VariableExprAST.hh 
	clang++ -c ./AST/VariableExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
binaryExprAST.o: ./AST/BinaryExprAST.cc ./AST/BinaryExprAST.hh 
	clang++ -c ./AST/BinaryExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 

unaryExprAST.o: ./AST/UnaryExprAST.cc ./AST/UnaryExprAST.hh 
	clang++ -c ./AST/UnaryExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
callExprAST.o: ./AST/CallExprAST.cc ./AST/CallExprAST.hh 
	clang++ -c ./AST/CallExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
forExprAST.o: ./AST/ForExprAST.cc ./AST/ForExprAST.hh 
	clang++ -c ./AST/ForExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
printAST.o: ./AST/PrintAST.cc ./AST/PrintAST.hh 
	clang++ -c ./AST/PrintAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
varExprAST.o: ./AST/VarExprAST.cc ./AST/VarExprAST.hh 
	clang++ -c ./AST/VarExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
whileExprAST.o: ./AST/WhileExprAST.cc ./AST/WhileExprAST.hh 
	clang++ -c ./AST/WhileExprAST.cc -I/usr/lib/llvm-11/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
parser.cc, parser.hh: parser.yy 
	bison -o parser.cc parser.yy -Wcounterexamples

scanner.cc: scanner.ll
	flex -o scanner.cc scanner.ll

clean:
	rm -f *~ *.o kfe scanner.cc parser.cc parser.hh
