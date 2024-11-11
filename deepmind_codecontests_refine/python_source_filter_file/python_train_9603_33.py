from sys import stdin, stdout  
from math import ceil
t=int(stdin.readline())
for _ in range(t):
    #n=int(stdin.readline() )
    #arr=list(map(int, stdin.readline() .strip().split()))
    a,b,c,d=(map(int, stdin.readline().strip().split()))
    #s=stdin.readline()
    #stdout.write(str(cp))
    #stdout.write("\n")

    if((a>b) and (c-d)<=0):
        print(-1)
    else:
        if(a<=b):
            print(a)
        else:
            mul=c-d
            num = int(ceil((a-b)/(mul)))
            ans=num*c
            print(ans+b)
