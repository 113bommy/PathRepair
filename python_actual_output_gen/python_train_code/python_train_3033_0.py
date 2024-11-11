(b, d, s) = map(lambda x: int(x), input().split(" "))

ans = 10 ** 18 + 1

if b >= max(d, s):
	ans = min(ans, max(b - 1 - d, 0) + max(b - 1 - s, 0)) 
if d >= max(b, s):
	ans = min(ans, max(d - 1 - b, 0) + max(d - 1 - s, 0)) 
if s >= max(b, d):
	ans = min(ans, max(s - 1 - b, 0) + max(s - 1 - d, 0)) 
	
print(ans)