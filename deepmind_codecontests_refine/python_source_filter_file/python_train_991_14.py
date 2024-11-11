# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
a=list(map(int,input().split()))
if n==1:
	if a[0]<15:
		print(a[0]+15)
		exit()
	else:
		print('15')
		exit()	
for i in range(n-1):
	if a[0]>15:
		print('15')
		exit()
	elif a[i+1]-a[i]>15:
		print(a[i]+15)	
		exit()
print(min(90,a[-1]+15))				
	
			
		