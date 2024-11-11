n = int(input())
s = list(input())
d = {'0': 0, '1': 0, '2': 0}
for i in range(n):
	d[s[i]]+= 1
f = n // 3

for i in range(n):
	if d[s[i]] > f and d['0'] < f:
		d[s[i]]-= 1
		s[i] = '0'
		d[s[i]]+= 1

for i in range(n - 1, -1, -1):
	if d[s[i]] > f and d['2'] < f:
		d[s[i]]-= 1
		s[i] = '2'
		d[s[i]]+= 1

for i in range(n - 1, -1, -1):
	if s[i] == '0' and d[s[i]] > f and d['1'] < f:
		d[s[i]]-= 1
		s[i] = '1'
		d[s[i]]+= 1

for i in range(n):
	if s[i] == '0' and d[s[i]] > f and d['1'] < f:
		d[s[i]]-= 1
		s[i] = '1'
		d[s[i]]+= 1
print(''.join(s))