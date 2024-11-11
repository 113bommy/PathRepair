def main():
	N,P = map(int,input().split())
	S = [int(s) for s in list(input().strip())][::-1]
	num = 0
	ans = 0
	if P == 2 or P == 5:
		for i in range(N):
			if S[i]%P == 0:
				ans += N-i
		print(ans)
		return
	L = [0]*P
	L[0]=1
	t = 0
	s = 1
	for z in S:
		t = (z*s+t)%P	
		L[t]+=1
		s=s*10%P
	for l in L:
		ans += l * (l - 1) // 2
	print(ans)

if __name__ == '__main__':
	main()
