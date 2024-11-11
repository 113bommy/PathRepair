a = int(input())
t = input()
t = t.split()
t = [int(t[i]) for i in range(a)]
sum = 0
for i in t:
	sum += i
t = sorted(t)
k = sum / 2
c = 0
while sum >= k:
	c += 1
	sum -= t[0]
	del(t[0])

print(c)