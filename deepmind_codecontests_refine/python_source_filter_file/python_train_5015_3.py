import sys
input = sys.stdin.readline
q = int(input())
aux = 'RGB'
def fun(k,s,ini):
	tam = 0
	ans = int(1e5)
	change = 0
	i = 0
	j = 0
	while len(s) > i:
		while len(s) > i and k > tam:
			change += (1 if aux[(ini+i)%3] != s[i] else 0)
			tam += 1
			i += 1
		if tam == k:
			ans = min(ans,change)
		change -= (1 if s[j] != aux[(ini+j)%3] else 0)
		j += 1
		tam -= 1
	return ans

for _ in range(q):
	n,k = map(int,input().split(' '))
	s = input()
	print(min(fun(k,s,0),min(fun(k,s,1),fun(k,s,2))))
	
	
	
	
