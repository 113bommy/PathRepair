# import sys
# sys.stdin = open('D:/FILES/Programming/input.txt', 'r')
n = int(input())
a = list(map(int, input().split()))
b = a[:]
k = 0
a.sort()
for i in range(n):
	if b[i]!=a[i]:
		k += 1
if k > 2:
	print("NO")
else:
	print("YES")
# print(a)
# print(b)