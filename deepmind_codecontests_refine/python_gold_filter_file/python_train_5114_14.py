n = int(input())
lst = list(map(int, input().split()))
k = 0
for i in range(1,n-1):
	if lst[i] == 0 and lst[i - 1] == lst[i + 1] == 1:
		lst[i + 1] = 0
		k += 1
#print(lst)
print(k)