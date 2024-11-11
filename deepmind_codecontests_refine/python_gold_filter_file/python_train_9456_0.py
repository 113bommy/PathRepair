import sys
a,b,c,d=[i for i in input()]
op=["+","-"]
for i in op:
  for j in op:
    for k in op:
      if eval(a+i+b+j+c+k+d)==7:
        print(a+i+b+j+c+k+d+"=7")
        sys.exit()