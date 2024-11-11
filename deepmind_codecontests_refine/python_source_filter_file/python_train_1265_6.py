n,k = map(int, input().split())
if k == 1:
	print('1' + '0' * (n - 1))
dist = (n - k) // 2
s = '1' + dist * '0'
for i in range(n // len(s)):
    print(s, end='')
print(s[0:n % len(s)])