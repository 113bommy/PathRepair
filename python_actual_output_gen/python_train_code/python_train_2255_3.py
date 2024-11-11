n = int(input())
s = [int(i) for i in input().split()]
m = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
d = dict()
r = []
for i in s:
	if i in d:
		d[i]+=i
	else:
		d[i] = 1
for i in a:
	if i not in d:
		d[i] = 0
for i in b:
	if i not in d:
		d[i] = 0
films = []
for i in range(m):
	films.append((i+1, (d[a[i]], d[b[i]])))
films.sort(key=lambda i: i[1], reverse = True)
print(films[0][0])

	
