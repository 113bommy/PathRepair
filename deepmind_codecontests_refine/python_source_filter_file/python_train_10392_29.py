n = int(input())
p,d = [],[]
for _ in range(n):
	x,y = (int(i) for i in input().split())
	p.append((x,y))
a = sum(p[0])%2
def f(i,j):
	s,s2,ans = bin((i+j+2**31-1)//2)[::-1][:-2],bin((i-j+2**31-1)//2)[::-1][:-2],""
	s,s2 = s+(31-len(s))*"0",s2+(31-len(s2))*"0"
	for i in range(31):
		if s[i]==s2[i]=="0": ans+="L"
		elif s[i]==s2[i]=="1": ans+="R"
		elif int(s[i]): ans+="U"
		else: ans+="D"
	return ans
if any(a!=sum(p[i])%2 for i in range(n)): print(-1)
else:
	if a-1: d.append("1")
	print(32-a)
	for i in range(31): d.append(str(2**i))
	print(" ".join(d))
	if a:
		for i,j in p: print(f(i,j))
	else:
		for i,j in p: print("L"+f(i-1,j))