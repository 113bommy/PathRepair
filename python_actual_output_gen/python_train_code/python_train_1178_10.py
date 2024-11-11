n,a=map(int,input().split())

apples=[a+i for i in ragen(n)]
eat=min(apples,key=lambda x:abs(x))
res=sum(apples)-eat

print(res)