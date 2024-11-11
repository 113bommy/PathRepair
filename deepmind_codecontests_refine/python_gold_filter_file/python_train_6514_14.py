import sys
a,b = map(int,sys.stdin.readline().split())
if (a==0 and b==0):
	print("NO\n")
elif (abs(b-a)==1 or b-a==0):
	print("YES\n")
else:
	print("NO\n")
