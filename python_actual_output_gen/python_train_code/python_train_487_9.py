n = int(input())
fingers = sum(map(int , input().split()))
result = 0
for i in range(1,6):
	if (i+fingers)%2 != 1:
		result +=1
print(result)
 