n = int(input())
a = list(map(int, input().split()))
R = range(100)
c = [[] for _ in [0]*100]
for i in range(n*2):
	c[a[i]].append(i)
d = [0]*200
heap = 1
z = [0, 0, 0]
for i in R:
	if len(c[i]) == 1:
		z[heap]+=1
		d[c[i][0]] = heap
		heap = 3 - heap;
for i in R:
	if len(c[i]) > 1:
		z[1]+=1
		z[2]+=1
		while len(c[i]):
			d[c[i].pop()] = heap
			heap = 3 - heap

print(z[1]*z[2])
print(''.join(map(str, d[:n*2])))