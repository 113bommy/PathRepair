n,k=map(int,input().split())
a=[];f=[];l=[];m=[]
for i in range(n):
	a.append(input())
for i in range(n):
	if a==[]:break
	v=a.pop()
	t=v[::-1]
	if t in a:f.append(v);l.append(t);a.remove(t)
	elif v==t:m.append(v)
print(len(f)*k*2+min(len(m),1)*k)
print(''.join(f)+(m[0] if m!=[] else '')+''.join(l))