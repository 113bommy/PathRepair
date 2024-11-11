n=int(input())
y=0
d=list(map(int,input().split()))
a,b=map(int,input().split())
for i in range(1,b):
	for j in range(i-1,i+1):
		y+=d[j]
		# j+=1
		break
		# y-=d[j-1]
print(y)
