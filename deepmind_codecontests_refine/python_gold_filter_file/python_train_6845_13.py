n , m = list(map(int,input().split()))
l = list(map(int,input().split()))
p = set(l)
k = list(p)
if len(p)>=m:
	print("YES")
	for i in range(m):
		print(l.index(k[i])+1,end = " ")
elif len(p)<m:		
	print("NO")