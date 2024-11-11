# import sys
# sys.stdin = open("F:\\Scripts\\input","r")
# sys.stdout = open("F:\\Scripts\\output","w")


MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

n , p = I()
s = input()
a = [0]*n
p -= 1
if p > n//2:p = n - p - 1
for i in range(n//2):
	a[i] = abs(ord(s[i]) - ord(s[n - i -1]))
	a[i] = a[n - i - 1] = min(a[i] , 26 - a[i])
ind = 0
s = sum(a)
s = s//2
if s == 0:
	print(0)
else:
	l = r = -1
	for i in range(n//2):
		if a[i]:
			l = i
			break
	for j in range(n//2 - 1, - 1, -1):
		if a[j]:
			r = j
			break
	# print(a)
	# print(p,l,r)
	if p == l or p == r:
		print(s + (r - l))
	else:
		print(min(abs(l - p) + s + (r - l) , abs(r - p) + s + (r - l)))