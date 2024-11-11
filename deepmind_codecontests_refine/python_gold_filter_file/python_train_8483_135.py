l = list(map(int,input().split()))
l1 = []
count = 0
n = max(l)-min(l)
l1.append(min(l))
while(n>0 and n!=1):
	n = n-2
	count = count+1
l1.append(count)
for i in range(len(l1)):
	print(l1[i],end = " ")	