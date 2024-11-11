n = list(map(int, input().split()))
l = list(map(int, input().split()))
ll = list(map(int, input().split()))
z = zip(l, ll)
t = [p[0] - p[1] for p in z]
temp = zip(t, l , ll)
temp = sorted(temp)
count = 0
ans = 0
for a, b, c in temp :
	if count < n[1] or a < 0:
		ans += b
		count += 1
	else:
		ans += c
print(ans)