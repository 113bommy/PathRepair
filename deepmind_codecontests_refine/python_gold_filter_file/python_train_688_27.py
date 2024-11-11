n = int(input())
s = ['o' for _ in range(n)]
a = 0
b = 1
s[a] = 'O'
while b < n:
	a,b = b, a+b
# 	print(b)
	if b <= n: s[b-1] = 'O'
print(''.join(s))