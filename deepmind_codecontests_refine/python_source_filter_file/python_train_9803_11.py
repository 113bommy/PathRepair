def pr(a):
	ans=''
	for i in range(len(a)):
		ans+=str(a[i])+" "
	return ans
def pros(a):
	for i in range(2,int(a**0.5)):
		if a%i==0:
			return False
	return True
def mini(a):
	for i in range(2,int(a**0.5)):
		if a%i==0:
			return i
n=int(input())
a=2
lis=[]
for i in range(2,n+1):
	if i%2==0:
		lis.append(1)
	elif pros(i):
		lis.append(a)
		a+=1
	else: lis.append(lis[mini(i)-2])

print(pr(lis))