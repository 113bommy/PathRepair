n,k=map(int,input().split())
s[0]*10**5
for i in range(n):
  a,b=map(int,input().split())
  s[a-1]+=b
i=0
while k>0:
  k-=s[i]
  i+=1
print(i)