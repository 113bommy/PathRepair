N = int(input())
ans = ""

while num > 0:
	N -= 1
	ans += chr(ord('a') + N % 26)
	N //= 26

print(ans)