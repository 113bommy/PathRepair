n = int(input())
cnt = 0
buf = [100, 20, 10, 5, 1]
for i in buf:
	cnt += n // i; n %= i if n // i >= 1 else 1
	
print(cnt)
	
