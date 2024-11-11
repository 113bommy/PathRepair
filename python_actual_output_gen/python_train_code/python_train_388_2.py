t = int(input())
l = list(map(int,input().split()))
k = l.index(max(l))
r = l.index(min(l))
l1 = max(k+1,r+1,t-k-1,t-r-1)
if l1 == t:
	print(t-1)
else:
	print(l1)