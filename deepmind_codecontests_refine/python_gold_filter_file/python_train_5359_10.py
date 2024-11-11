
n,m = [int(x) for x in input().split()]
temp = [int(x) for x in input().split()]
boys = [0]*n
girls = [0]*m
for i in temp[1:]:
	boys[i] = 1

temp = [int(x) for x in input().split()]
for i in temp[1:]:
	girls[i] = 1

for i in range((n*m)*2):
	boys[i%n] = girls[i%m] = boys[i%n] | girls[i%m]

if 0 in boys or 0 in girls:
	print("NO")
else:
	print("YES")