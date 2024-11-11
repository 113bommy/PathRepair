R = lambda:map(int, input().split())
n, m = R()
s = 0
B = []
A = list(R())
for i in A:
	s += i
	B.append(s)
print(max(0,max(0, m - max(B)) - max(0, -min(B)) + 1))