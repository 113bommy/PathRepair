# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n,k=map(int,input().split())
a=1
while (n*a)%10!=0 and (n*a)%10!=10:
	a+=1
print(a)	
