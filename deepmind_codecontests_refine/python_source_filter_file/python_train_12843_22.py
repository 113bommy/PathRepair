n,k=map(int,input().split())
l=list(input().split())
ans=0
for i in l:
    a=l.count('4')
    b=l.count('7')
    if (a+b)<k:
        ans=ans+1
print(ans)