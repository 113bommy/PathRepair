def same(x, c):
	x=[i for i in str(x)]
	c=[i for i in str(c)]
	for i in x:
		if i in c:
			return True
	return False
 
x=int(input())
ans=0
for i in range(1, int(x**0.5)+1):
	if x%i==0:
		if x//i==i:
			if same(x//i, x):
				ans+=1
		else:
			if same(i, x):ans+=1
			if same(x//i, x):ans+=1
print(ans)