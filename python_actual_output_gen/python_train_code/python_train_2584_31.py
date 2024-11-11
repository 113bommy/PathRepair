n,q=map(int,input().split())
s=list(input())
ac=[0]*n
for i in range(1,n):
  ac[i]=ac[i-1]
  if s[i-1]+s[i]=='AC':
    ac[i]+=1
print(*ac)
for _ in range(q):
  l,r=map(int,input().split())
  print(ac[r-1]-ac[l-1])