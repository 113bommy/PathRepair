
a,b=map(int,input().split())
l=list(map(int,input().split()))
if sum(l)+10*(a-1)>b:
    print("-1")
else:
    print((b-sum(l))//5)
