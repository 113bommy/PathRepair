import re
N = int(input())
S = []
a, b, ab,c = 0, 0, 0, 0
for i in range(N):
	S.append(input())
	c += len(re.findall("AB", S[i]))
	if S[i][-1] == "A" and S[i][0] == "B":
		ab += 1
	if S[i][-1] == "A":
		a += 1
	if S[i][0] == "B":
		b += 1
if ab == a == b:
	seq = ab -1
else:
	seq = min (a,b)

print(seq + c)