from random import randint
import sys

if __name__=='__main__':
    n,k=map(int,input().split())

    def f(x,y):
        print(x,y)
        sys.stdout.flush()
        str=input()
        if str=='Bad':
            sys.exit(0)
        else:
           return str=="Yes"
    l,r=int(1),n
    while True:
        xx=55
        if r-l<xx:
            x=randint(l,r)
            if f(x,x):
                sys.exit(0)
        else:
            md=(l+r)//2
            if f(l,md):
                r=md
            else:
                l=md
        l=max(1,l-k)
        r=min(n,r+k)