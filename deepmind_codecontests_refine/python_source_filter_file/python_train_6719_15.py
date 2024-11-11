n,a = map(int, input().strip().split())
array = list(map(int, input().strip().split()))

dist = n-a
answer = 0
for i in range(dist+1):
	if (a-i <= 0):
		if array[a+i-1] == 1:
			answer += 1
	elif (a+i > n):
		if array[a-i-1] == 1:
			answer += 1
	elif (array[a-i-1] == 1 and array[a+i-1] == 1):
		if (i != 0):
			answer += 2
		else:
			answer += 1
print(answer)

