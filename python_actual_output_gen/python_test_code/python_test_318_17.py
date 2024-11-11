x=int(input())
m=100
ans=0
while m<=x:
    m=m+m//100
    ans+=1
print(ans)
