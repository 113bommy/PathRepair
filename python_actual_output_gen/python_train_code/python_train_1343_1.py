a, b, c = map(int,input().split())

aux = min(a,b,c)
resp=0
rsp=0

if(aux > 3):
	resp+= aux-3
	a -= (aux-3)
	b -= (aux-3)
	c -= (aux-3)

aux = min(a,b,c)

for i in range(aux):
	rsp = max(i + (a-i)//3 + (b-i)//3 + (c-i)//3,rsp)
 
print(rsp + resp)
