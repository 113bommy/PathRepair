n = int(input())
direction = input()
x = list(map(int,input().split()))
ind = direction.find("RL")
if ind == -1:
	print(ind)
	exit()
minimum = (x[ind+1]-x[ind])/2
for i in range(n-1):
	if direction[i]+direction[i+1]=='RL':
		if minimum>(x[i+1]-x[i])/2:
			minimum=(x[i+1]-x[i])/2
print(minimum)