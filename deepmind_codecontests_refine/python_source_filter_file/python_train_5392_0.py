n=int(input())
s=input()
n=n//2

if s[:n]==s[n:]:
	print("YES")
else:
	print("NO")