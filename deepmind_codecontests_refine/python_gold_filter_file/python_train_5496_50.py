m=int(input())
total=0
keta=0
for i in range(m):
	d,c=map(int,input().split())
	total+=d*c
	keta+=c
print(keta-1+(total-1)//9)
