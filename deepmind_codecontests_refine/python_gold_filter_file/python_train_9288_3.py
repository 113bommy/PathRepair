t = int(input())
for _ in range(t):
	n,d = map(int,input().split())
	if d<=n:
		print("YES")
		continue
	val = n // 2
	maxi = (n - val)*(val+1)
	#print(maxi)
	if(d<=maxi):
		print("YES")
	else:
		print("NO")
