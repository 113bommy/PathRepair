n,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

offsets=[None]*n
for i in range(n):
	offsets[i]=a[i]-b[i]
offsets.sort()
minus_range=0
for i in range(n):
	if offsets[i]>=0:
		minus_range=i
		break
print(sum(b)+sum(offsets[:max(k,minus_range)]))