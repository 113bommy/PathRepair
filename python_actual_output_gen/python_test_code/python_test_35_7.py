import sys
read=lambda:map(int,sys.stdin.buffer.readline().split())
n=list(read())[0]
s=[]
for i in range(n):
	l,r=read()
	s.append((l,-r,i))
s.sort()
ans=(-1,-1)
for i in range(1,n):
	if s[i][1]>=s[i-1][1]: ans=(s[i][2],s[i-1][2]);break
print(*ans)