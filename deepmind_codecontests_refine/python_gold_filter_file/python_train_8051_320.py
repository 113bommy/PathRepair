a = int(input())
b = list(map(int,input().split()))
s = 0
for i in range(a):
	s += b[i]
print(s  / a)