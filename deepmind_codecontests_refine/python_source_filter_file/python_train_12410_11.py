n = int(input())
for i in range(2):
	a,b,c = map(int,input().split())
	z= list(map(int,input().split()))
	x= list(map(int,input().split()))
	if max(z)>max(x):print("YES")
	else:print("NO")