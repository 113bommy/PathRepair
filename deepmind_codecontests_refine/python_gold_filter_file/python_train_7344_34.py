n,b,d=map(int,input().split())
a=list(map(int,input().split()))
cnt=0
res=0
for i in a:
    if(i<=b):
        cnt+=i
    if(cnt>d):
        res+=1
        cnt=0
print(res)
