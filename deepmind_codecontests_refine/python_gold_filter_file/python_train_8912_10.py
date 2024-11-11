from collections import defaultdict
dd=defaultdict(int)
n=int(input())
s=input()
v=set()
cnt=0
v.add(0)
dd[0]=0
ans=0
for i in range(1,n+1):
  if s[i-1]=="0":
    cnt-=1
  else:
    cnt+=1
  if not cnt in v:
    dd[cnt]=i
    v.add(cnt)
  else:
    ans=max(ans,i-dd[cnt])
print(ans)