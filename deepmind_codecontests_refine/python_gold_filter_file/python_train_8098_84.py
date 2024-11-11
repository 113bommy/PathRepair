ans=0
N=int(input())
for i in range(1,N+1):
    if len(str(i))%2==1:
      ans+=1
print(ans)