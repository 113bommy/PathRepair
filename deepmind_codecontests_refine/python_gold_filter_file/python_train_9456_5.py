import sys
a,b,c,d=input()
op=["-","+"]

for i in op:
  for j in op:
    for k in op:
      o=a+i+b+j+c+k+d
      ans=eval(o)
      if ans==7:
        print(o+"=7")
        sys.exit()
