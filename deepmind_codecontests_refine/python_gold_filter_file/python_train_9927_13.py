# import sys
# sys.stdin = open("F:\\Scripts\\input","r")
# sys.stdout = open("F:\\Scripts\\output","w")


MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

n , = I()
l = I()
s = l.copy()
s.sort()
ops = 0
for i in range(n):
	if s[i] != l[i]:
		ops += 1
if ops <= 2:
	print("YES")
else:
	print("NO")