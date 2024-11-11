def main():
	n,k = map(int,input().split())
	if n%2==0:
		ans = n + 2*k
		print(ans)
		return
	else:
		for i in range(3,(n)+1):
			if n%i==0:
				ans = n + 2*(k-1) + i
				print(ans)
				return





t = int(input())
while t:
	main()
	t-=1