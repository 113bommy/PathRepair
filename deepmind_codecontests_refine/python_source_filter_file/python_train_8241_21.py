def f(n,m):
	s = 0
	if(n>m*20):
			for i in range(m,m*10,m):
				s += int(str(i)[len(str(i))-1])
			s = s*int(n/(m*10))
			for i in range(m*int(n/(m*10))*10,n,m):
				s += int(str(i)[len(str(i))-1])
			return s
	else:
		for i in range(m,n+1,m):
			s += int(str(i)[len(str(i))-1])
		return s


nt = int(input())
ans = []
for i in range(nt):
    n,m= input().split()
    ans.append(f(int(n),int(m)))
for i in ans:
    print(i)
