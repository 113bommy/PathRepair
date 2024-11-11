d = int(input())
n = int(input())
a = list(map(int,input().split()))
count = 0
for i in range(1,n):
	count += d-a[i]
print(count)