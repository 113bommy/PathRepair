a, b, c = map(int,input().split())



rsp = 0
aux = min(5,a,b,c)

for i in range(aux):
	rsp = max(i + (a-i)//3 + (b-i)//3 + (c-i)//3,rsp)
 
print(rsp)
