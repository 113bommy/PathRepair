n = int(input())

a = list(map(int, input().split()))

m = 1
ans = 1

j = 0
i = 1

a.sort()
#print(a)
while i < n:
	#print(a[i], a[j], a[i] - a[j], "i=", i, "ans=", ans,"j=", j,"m=", m)
	if a[i] - a[j] < 6:
		ans += 1
		i += 1
	else:
		ans -= 1
		j += 1
	m = max(m, ans)



'''if ans > m:
	m = ans
if max(a) == min(a):
	m = len(a)
if m == 0:
	m = 1'''

print(m)