
n, k = map(int, input().split())
su = sum(list(map(int, input().split())))
avg = su / n
i = 0
while avg < (k - 0.5):
	su += i * k
	i += 1
	n += 1
	avg = su / n

print(i)

