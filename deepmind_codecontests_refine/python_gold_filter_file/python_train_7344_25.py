'''input
1 1 1
1
'''
n, b, d = map(int, input().split())
a = list(map(int, input().split()))
s, t = 0, 0
for x in a:
	if x <= b:
		s += x
	if s > d:
		s = 0
		t += 1
print(t)