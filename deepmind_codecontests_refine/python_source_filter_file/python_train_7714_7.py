a,b = map(int,input().split())

print("YES")
for i in range(1,b-a+1+1,2):
	print(i,i+1)