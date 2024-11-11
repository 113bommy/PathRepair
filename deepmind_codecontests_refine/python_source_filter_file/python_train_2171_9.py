a,b,c=map(int, input().split())
ans=0
while a%2==0 and b%2==0 and c%2==0 and ans<100000:
    a,b,c=b//2+c//2,a//2+c//2,a//2+b//2
    ans+=1
if ans==10000:ans=-1
print(ans)