ii=lambda:int(input())
kk=lambda:map(int, input().split())
ll=lambda:list(kk())
x,d=kk()
v=1
s=[]
for i in range(35):
	if 2**i > x: break
	if (2**i)&x:
		s.extend([v]*i)
		s.append(v+10**9)
		v+=2*10**9
print(len(s))
print(*s)