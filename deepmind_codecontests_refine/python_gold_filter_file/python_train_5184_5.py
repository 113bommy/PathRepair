n=int(input())
a=list(map(int,input().split()))
c=[0]*(n+1)
c[0]=3
cnt=1
for i in a:
  cnt=cnt*c[i]%1000000007
  c[i]-=1
  c[i+1]+=1
print(cnt)