n, k1, k2 = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

difference = []
k = k1 + k2
for i in range(n):
	difference.append(abs(a[i]-b[i]))
while k != 0:
	if max(difference) >= 0:
		difference[difference.index(max(difference))] -= 1
		k -= 1
	else:
		difference[difference.index(min(difference))] += 1
		k -= 1

for i in range(n):
	difference[i] **= 2

print(sum(difference))