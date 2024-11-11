a,b=map(int,input().split())
c=0
for i in range(a,b+1)
	o=str(i)
  	if o==o[::-1]:c+=1
print(c)