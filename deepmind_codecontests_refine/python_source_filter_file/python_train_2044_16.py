n = int(input())
f = []
s = []
f1 = s1 = 0
for i in range(n, 0, -1):
	if f1 <= s1:
		f1 += i
		f.append(i)
	else:
		s1 += i
		s.append(i)
print(abs(f1 - s1))
print(*f)