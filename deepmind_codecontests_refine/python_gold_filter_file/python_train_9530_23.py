n=int(input())
def f(n):
	for i in range(n):
		s,bf,af=input().split()
		bf,af=int(bf),int(af)
		if bf>=2400 and af-bf>0:
			return "YES"
	return "NO"

print(f(n))