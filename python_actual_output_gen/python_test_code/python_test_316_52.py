n=input()
n=list(n)
m=['a','e','i','o','u']
b=['0','2','4','6','8']
c=0
for i in range(len(n)):
	if n[i] in m:
		c=c+1
	if n[i] in b:
		c=c+1
print(c)
