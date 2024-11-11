import shlex
a=str(input())
l=shlex.split(a)
b=int(l[0])*int(l[1])
if (b)==1:
    print(1)
else:
    print(int(b/2))