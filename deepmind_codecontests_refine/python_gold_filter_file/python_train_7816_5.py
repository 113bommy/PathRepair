#codeforces_1025A_live
gi = lambda: list(map(int,input().split()))
n = gi()[0]
s = input()
if n > 26 or n==1:
	print("Yes")
	exit();
if len(set(list(s))) == n:
	print("No")
else:
	print("Yes")