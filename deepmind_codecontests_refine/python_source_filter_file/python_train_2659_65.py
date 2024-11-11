l=input().split()
n=int(l[0])#total people
h=int(l[1])#height of fence
width=0
a=input().split()
for i in range(n):
	if int(a[i])<h:
		width+=1
	if int(a[i])>h:
		width+=2
print(width)