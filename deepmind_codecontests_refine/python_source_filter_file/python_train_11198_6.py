n, k = map(int, input().split())
t = n
for i in range(k):
	l, r = map(int, input().split())
	l = r - l + 1
	if l < t:
		t = l
print(t + 1)
print(' '.join([str(i % t) for i in range(n)]))