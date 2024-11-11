
n = int(input())
m = input()
if m[:n//2] == m[n//2:]:
	print("Yes")
else:
	print("No")