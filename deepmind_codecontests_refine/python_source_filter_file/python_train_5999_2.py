n=int(input())
l=list(map(int,input().split()))
a=max(l)
if a>25:
    print(25-a)
else:
    print(0)    