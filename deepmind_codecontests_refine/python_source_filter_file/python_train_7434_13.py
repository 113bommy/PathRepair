n,d=map(int,input().split())
a=list(map(int,input().split()))
m=int(input())
if m<=n:
    print(sum(a[:m]))
else:
    print(sum(a)-d*(m-n))