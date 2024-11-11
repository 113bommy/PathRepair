n=int(input())
s,c=input(),0
for i in range(n):
	for j in range(1,n-i,2):
		z=s[j:j+2]
		c+=z.count('R')==z.count('L') and z.count('U')==z.count('D')
print(c)