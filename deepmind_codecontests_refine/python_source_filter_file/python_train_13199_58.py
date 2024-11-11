a=int(input())
for x in range(int(a**0.5),0,-1):
	if a%x==0:
    d=int(a//x)
    break
print(d+x-2)
