k, a, b = map(int, input().split())
ans = a//k + b//k

wona = a//k
rema = a%k

wonb = b//k
remb = b%k

if(wona > 0 or remb == 0) and (wonb > 0 or remb == 0):
	print(ans)
else:
	print(-1)