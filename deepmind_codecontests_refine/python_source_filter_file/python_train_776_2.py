n = input()
z = float("-inf")
l = [0 for i in range(len(n))]
for i in range(len(n)):

	l[i] = int(n[i])

k = max(l)
r = [[0 for i in range(len(n))] for j in range(k)]

for i in range(len(n)):

	for j in range(int(n[i])):
		r[j][i] = r[j][i] + 1
str_ = ""
# print(r)
print(r)
for i in range(len(r)):
	s = ""
	flag = 0
	for j in range(len(r[i])):
		if r[i][j] == 0 and flag == 0:
			continue
		if r[i][j] == 1:
			flag = 1
		s = s + str(r[i][j])

	str_ = str_ + s + " "
print(k)
print(str_)