#  prottoyfuad

n, s = map(int, input().split())
a = []
for i in range(n) :
	h, m = map(int, input().split())
	a.append(h*60 + m)
if(a[0] > s) :
    print("0 0")
    exit(0)
ans = -1
for i in range(2, n) :
	if(a[i] - a[i-1] - 2 >= 2 * s) :
		ans = a[i - 1] + s + 1
		break
if ans == -1 :
	ans = a[n - 1] + s + 1
print(ans // 60, end = ' ')
print(ans % 60)