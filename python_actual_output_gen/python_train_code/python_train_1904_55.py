M = int(input())
d = [0] * M
c = [0] * M
for i in range(M):
	d[i], c[i] = map(int, input().split())
D = 0
S = 0
for i in range(M):
	D += c[i]
	S += d[i] * c[i]
print((D - 1) + S // 9)
