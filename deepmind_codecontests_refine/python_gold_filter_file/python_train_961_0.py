import sys
input = sys.stdin.buffer.readline
n=int(input())
*a,=map(int,input().split())
inA=[0]*(n+5)
for x in a:
	inA[x]+=1
keep=[0]
ma=0
ans=[]
for i in range(n):
	if keep and not inA[keep[0]]:
		ans.append(keep.pop(0))
	else:
		ma+=1
		while inA[ma]:
			keep.append(ma)
			ma+=1
		ans.append(ma)
	if ma+1<a[i]:
		print(-1)
		exit()
	inA[a[i]]-=1
print(*ans)