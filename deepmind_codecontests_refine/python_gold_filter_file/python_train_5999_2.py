n=int(input())
l=list(map(int,input().split()))
a=max(l)
if a>25:
    print(a-25)
else:
    print(0)    