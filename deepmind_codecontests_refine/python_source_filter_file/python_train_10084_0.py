
def read():
    return int(input())

def reads(sep=None):
    return list(map(int, input().split()))

def f(m, a):
	sa = set(a)
	seen = set()
	r = []
	for n in a[::-1]:
		if n not in seen:
			r.append(n)
			seen.add(n)
	for i in range(m):
		if (i+1) not in sa:
			r.append(i+1)
	return r

def isSorted(a):
	for i in range(1, len(a)):
		if a[i-1] > a[i]:
			return False
	return True

n, m = reads()
q = read()
a = reads()

r = f(m, a)
count = [0] * (m+1)
count[0] = n

table = [-1] * (m+1)
for i in range(len(r)):
	table[r[i]] = i

for aa in a[::-1]:
	index = table[aa]
	if 0 < count[index]:
		count[index] -= 1
		count[index+1] += 1

to = 0
for i in range(m):
	if 0 < count[i]:
		to = i
		break

if isSorted(r[to:]):
	print('Yes')
else:
	print('No')
