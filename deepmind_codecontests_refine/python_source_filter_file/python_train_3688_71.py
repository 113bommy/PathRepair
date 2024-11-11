n=int(input())
d=list(map(int, input().split()))
a,b=map(int, input().split())
if a==b:
    print(0)
else:
    x=sum(d[:b-a])
    print(x)