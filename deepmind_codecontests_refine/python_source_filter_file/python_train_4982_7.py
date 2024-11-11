n,k = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
a,num,ans = sorted(a),0,0
for i in range(n-1,-1,-1):
	if num+a[i]<k: num+=a[i]
	else: ans = i
print(ans)