n,m= map(int,input().split())
s=list(map(int,input().split()))[:m]
s.sort()
print(s)
diff=s[n-1]-s[0]
for i in range(0,(m-n+1)):
	if(s[i+n-1]-s[i]<diff):
		diff=s[i+n-1]-s[i]
print(diff)
	