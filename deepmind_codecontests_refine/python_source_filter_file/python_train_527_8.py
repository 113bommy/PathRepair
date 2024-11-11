import sys
n,k=map(int,input().split())
s=input()
r=[]
for i in s:
  r.append(i)
r.sort()
pointer=1
ans=ord(r[0])-ord('a')+1
last=ord(r[0])
for i in range(k-1):
  while pointer<n and ord(r[pointer])<=last+2:
    pointer+=1
  if pointer==n:
    print(-1)
    sys.exit()
  ans+=ord(r[pointer])-ord('a')+1
  last=ord(r[pointer])
print(ans)