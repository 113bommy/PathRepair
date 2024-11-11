n, k = map(int, input().split())
s = list(input())

# 累積和
a = [0]
if s[0] == "0":
	a.append(0)
for i in range(n):
	if i == n-1 or s[i+1] != s[i]:
		a.append(i+1) # 累積和

# print(s[-1])
if s[-1] == "0":
	a.append(a[-1])

if len(a) <= 2*k+1: # 2*k+1
	print(n)
else:
	ans = 0
	for j in range(0, len(a) - 2*k - 1, 2): # len(a)は奇数
		ans = max(ans, a[j+2*k+1] - a[j])
	print(ans)
