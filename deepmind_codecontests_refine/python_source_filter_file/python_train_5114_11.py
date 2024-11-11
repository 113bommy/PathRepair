n=int(input())
l=input().split()
x=1
count=0
while x<n-2:
	if l[x]=='1' and l[x+1]=='0' and l[x+2]=='1':
		count+=1
		x+=3
	else:
		x+=1
print(count)