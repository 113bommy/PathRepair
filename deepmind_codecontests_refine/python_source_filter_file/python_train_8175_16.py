s = input()
n = len(s)

N = 0

if n % 2 == 0:
	N =  n // 2
else:
	N = n // 2 + 1
flag = True

def check(l, r):
	same = ["A", "H", "I", "M", "O", "o", "T", "U", "V", "v", "W", "w", "X", "x"]
	if l == r and (l in same):
		return True
	if l == "b" and r =="d":
		return True
	if l == "d" and r == "b":
		return True
	if l == "p" and r == "q":
		return True
	if l == "q" and r == "p":
		return True
	return False
for i in range(N):
	left = i
	right = n-1-i
	lc = s[left]
	rc = s[right]

	if ( not check(lc, rc) ):
		flag = False

if flag:
	print("TAK")
else:
	print("NIE")

