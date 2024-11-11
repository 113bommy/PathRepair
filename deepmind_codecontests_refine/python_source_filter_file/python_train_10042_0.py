a=[]
for i in range(1,33):
	a.append((i*(i+1))//1)
t=int(input())
print('YES' if t in a else 'NO')