MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

n, = I()
l = I()
if n == 1:
	print(0)
	exit()
# a = [17669]*n
print(n+1)
print(1, n, 1)
print(2, n, 17669)
for i in range(n - 1):
	print(1, i+1, 17669 - i)
	# a[i] = a[i]%(17669-i)
# print(a)