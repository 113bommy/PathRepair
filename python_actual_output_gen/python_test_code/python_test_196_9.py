n, m = map(int, input().split())
a = list(map(int, input().split()))
p=1
if n > 10000:
	print(0)
	exit()
for i in range(0, n-1):
    for j in range(i, n):
        if i<j:
            p*=abs(a[i]-a[j])%m
        
print(p)