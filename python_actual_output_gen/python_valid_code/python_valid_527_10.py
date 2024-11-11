import sys
input = sys.stdin.readline
a=int(input())
b=0
while b<a:
    c=input().split(' ')
    d=int(c[0])
    e=int(c[1])
    f=(d+e)/2
    g=0
    if f.is_integer()==False:
        print(-1)
    if f.is_integer==True:
        if d==0 and e==0:
            print(0)
            g=1
        if d==e and g==0:
            print(1)
            g=1
        if g==0:
            print(2)
    b=b+1

