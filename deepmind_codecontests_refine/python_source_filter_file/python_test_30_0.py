
def check(p,s,a):
	l,r=0,len(s)-1

	ans = len(p)
	while l<r:
		if s[l]==a and s[r]==a:
			ans+=2
			l+=1
			r-=1
		elif s[l]==a:
			l+=1
		elif s[r]==a:
			r-=1
		else:
			l+=1
			r-=1
	if l==r and s[l]=='a':
		ans+=1

	return ans

INF = float('inf')

for _ in range(int(input())):
	N = int(input())
	S = input()

	if S==S[::-1]:
		print(0)
		continue

	ans = INF
	for a in [chr(c) for c in range(ord('a'),ord('z')+1)]:
		tmp = [c for c in S if c!=a]
		if tmp==tmp[::-1]:
			maxlen = check(tmp,S,a)
			#print(maxlen,a)
			ans = min(ans, N-maxlen)
	print(ans if ans!=INF else -1)


