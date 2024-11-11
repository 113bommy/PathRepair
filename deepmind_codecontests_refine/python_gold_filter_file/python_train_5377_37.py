# import sys
# sys.stdin=open("test.in","r")
# sys.stdout=open("test.out","w")


n=int(input())	
c=0
for i in range (1,int(n/2)+1):
	if (n-i)%i==0:
		c+=1
print(c)