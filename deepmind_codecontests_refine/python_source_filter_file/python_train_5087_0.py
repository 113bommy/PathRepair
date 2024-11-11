N = int(input())
a = list(map(int, input()split()))
c = 0
for i in range(N):
	if a[a[i] - 1] == i + 1:
		c += 1

print(int(c / 2))