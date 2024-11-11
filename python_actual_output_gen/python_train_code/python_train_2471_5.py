n,k = map(int,input().split(" "))
a = list(map(int,input().split(" ")))
t = list(map(int,input().split(" ")))
inc = [0] * n

base = 0
for i in range(n):
	if t[i] == 0:
		inc[i] = a[i]
	else:
		base += a[i]

val = 0
val = sum(inc[:k])
ans = val
for i in range(1,n-k):
	ans = max(ans,(val - inc[i-1] + inc[i+k]))
	val += (inc[i+k] - inc[i-1])

print(base+ans)
