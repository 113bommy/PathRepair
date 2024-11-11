import sys

n=int(sys.stdin.readline())

a=[int(i) for i in sys.stdin.readline().split()]

b=[int(i) for i in sys.stdin.readline().split()]


x=0
y=0

fine_car=[0]*(n+1)
# found_car=[0]*(n+1)

while(x<n and y<n):
	if(fine_car[a[x]]==1):
		x+=1
	if(a[x]==b[y]):
		# found_car[a[x]]=1
		x+=1
		y+=1
	else:
		# cars are not same
		fine_car[b[y]]=1
		y+=1

count=0

for h in range(n+1):
	count+=fine_car[h]

print(count)	


