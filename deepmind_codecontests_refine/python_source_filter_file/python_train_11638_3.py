n,k = map(int,input().split())
s=[]
for i in range(k):
  s= int(input())
  l=list(map(int,input().split()))
  s=s+l
r=set(s)
print(n-len(r))
  