n,k = map(int,input().split())
l = list(map(int,input().split()))
t = 0
t1 = 0
for i in range(n):
	if l[i] >= 2*k:
		r = l[i]//(2*k)
		l[i] = l[i]%(2*k)
		t = t + r
for i in range(n):
	if l[i] > k:
		r = l[i]//k
		l[i] = l[i]%k
		t = t + r
for i in range(n):
	if l[i] <= k and l[i] != 0:
		t1 = t1 + 1
if t1%2 == 1:
	print(t+t1//2+1)
else:
	print(t+t1//2)
