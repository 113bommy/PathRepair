a,b=map(int,input().split())
lis=list(map(int,input().split()))
if a==1 and b>a:
    print((b-sum(lis))//5)
elif b-sum(lis)>(a-1)*10:
    print((b-sum(lis))//5)
else:
    print(-1)
    