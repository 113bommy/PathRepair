n=int(input())
itv=[]
for i in range(n):
  x,l=map(int,input().split())
  itv+=[(x+l-1,x-l+1)]
itv=sorted(itv)
l=-10**18
cnt=0
for t,s in itv:
  if l<s:
    l=t
    cnt+=1
print(cnt)