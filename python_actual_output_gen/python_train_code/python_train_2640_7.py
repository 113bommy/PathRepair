import sys



def Divide(a):
	if (len(a)==0):
		return 0
	rm_sum=0
	i=0
	j=len(a)-1
	sum1=a[0]
	sum3=a[len(a)-1]
	while(i<=j):
		if sum1<sum3:
			i+=1
			sum1+=a[i]
		elif sum1>sum3:
			j-=1
			sum3+=a[j]
		else:
			rm_sum+=sum1
			i+=1
			j-=1
			sum1=a[i]
			sum3=a[j]
	return rm_sum
		

n=int(input())
a=input().split()

for i in range(len(a)):
	a[i]=int(a[i])

print(Divide(a))

