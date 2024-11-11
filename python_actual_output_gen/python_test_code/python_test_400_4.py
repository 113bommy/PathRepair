li = input().split(' ')
n = int(li[0])
m = int(li[1])
k = int(li[2])

a = []
li = input().split(' ')
for i in range(n):
	a.append(int(li[i]))

a.sort()
ans = a[n-1]*m
diff = a[n-1] - a[n-2]
ans -= diff * (m/(k+1))


print(int(ans))