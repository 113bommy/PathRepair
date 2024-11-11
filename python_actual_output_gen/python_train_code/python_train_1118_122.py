a,b,k=map(int,input().split())
if k<=a:
    print(a-k,b)
else:
    print(0,min(0,b-(k-a)))