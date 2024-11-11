N = int(input())
a = list(map(int,input().split()))
b = []
j = 0
for i in a:
	if i < 3200:
		b.append(int(i/400))
	if i >= 3200:
		j += 1
k = len(set(b))
if k == 0 and j > 0:
	k = 1
print(k,k+j)