n,a,b=map(int,input().split())
l=[int(input())for i in range(n)]
a-=b
def  enough(x):
    return sum((h-b*x+a-1)//a for h in l)<=x
#(ng,ok]type
ok,ng=10**9,-1
# [ok,ng)type->eraseng,ok=ok,ng
eps=10**(-10)
while abs(ok-ng)>1:
    mid=(ok+ng)//2
    if enough(mid):ok=mid
    else:ng=mid
print(ok)