n,x = map(int,input().split())
L = list(map(int,input().split()))
d = 0
cnt = 0
for l in L:
	d += l
	if(d <= x):
		cnt += 1
print(cnt)