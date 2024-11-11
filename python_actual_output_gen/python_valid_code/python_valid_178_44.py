n = int(input())
s = input();count = 0
A = []
L = "abcdefghijklmnopqrstuvwxyz"
s = s.lower()
for k in s:
	if(k in L and (k not in A)):
		A.append(k)
if len(A) == 26:
	print("YES")
else:
	print(len(A),"NO")