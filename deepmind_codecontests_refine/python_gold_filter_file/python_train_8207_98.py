a=int(input())
ans=a//11*2
a%=11
if 6>=a>=1:ans+=1
elif a!=0:ans+=2
print(ans)