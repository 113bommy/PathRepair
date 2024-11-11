n=int(input())
s=[0]*1001
a=list(map(int,input().split()))
for i in range(n):
	s[a[i]]+=1
z=max(s)
if z//2>n-z:
	print("NO")
else:
	print("YES")