n,x,y=map(int,input().split())
a=list(map(int,input().split()))
if x>y:print(n)
else:
    k=1
    for i,item in enumerate(a):
        if item<x:k+=1
    print(k//2)