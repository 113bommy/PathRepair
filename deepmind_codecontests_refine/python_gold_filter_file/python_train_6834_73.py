k = int(input())
ans = ""
if(k > 36):
	print(-1)
else:
	t = int(k/2)
	ans = ans+t*"8"
	t = int(k%2)
	ans = ans+t*"4"
	print(int(ans))