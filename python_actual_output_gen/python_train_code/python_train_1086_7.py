a = input()
b = input()
n = len(a)
m = len(b)
ans = 0
if (n>m):
	a = a[n-m::]
	ans+=(n-m)
elif (n<m):
	b = b[m-n::]
	ans+=(m-n)
n = min(n,m)
i = n-1
tec_ans=n
while (a[i]==b[i] and i>-1):
	tec_ans = i*2
	i-=1
print(ans+tec_ans)

