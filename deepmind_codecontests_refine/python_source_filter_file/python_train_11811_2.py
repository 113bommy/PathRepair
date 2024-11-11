n = int(input())
l = list(map(int,input().split()))
l.sort()
flag = 0
for i in range(1,n-1):
	if i == l[i-1]:
		continue
	else:
		flag = 1
		print(i)
		break
if flag == 0:
	print(n)