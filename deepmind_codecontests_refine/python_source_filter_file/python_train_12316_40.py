# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("output1.out",'w')
a=[int(input()) for i in range(4)]
n=int(input())
c=0
for x in range(n):
	if x%a[0]==0:
		c+=1
	elif x%a[1]==0:
		c+=1
	elif x%a[2]==0:
		c+=1
	elif x%a[3]==0:
		c+=1
print(c)					