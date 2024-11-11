n,m = input().split()
n = int(n)
m = int(m)
x = min(n,m)
print(x+1)
for i in range(x):
	print(i,i+1)
print(x,0)