n=int(input())
s=input()
t=input()

moves=[]
s1_z=0
s2_z=0
def check(num):
	ret=0
	mx=0
	for z in moves:
		ret+=(num*z)
		mx=max(mx,ret)
		if ret<0:
			ret=0
	return mx

for i in range(n):
	if s[i]=='0':
		s1_z+=1
	if t[i]=='0':
		s2_z+=1
	if s[i]!=t[i]:
		if s[i]=='1':
			moves.append(-1)
		else:
			moves.append(1)			

print (moves)

if s1_z!=s2_z:
	print(-1)
else:
	print(max(check(1),check(-1)))