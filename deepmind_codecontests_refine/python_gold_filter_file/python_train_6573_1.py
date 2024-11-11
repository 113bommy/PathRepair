n,k=map(int,input().split())
mas=list(map(int,input().split()))
ans=0
q=[0]*k
for i in range(n):
     q[mas[i]%k]+=1
ans+=q[0]-q[0]%2
for i in range(1,k//2+1):
     if i==k-i:
          ans+=q[i]-q[i]%2
     else:
          ans+=min(q[i],q[k-i])*2
print(ans)
