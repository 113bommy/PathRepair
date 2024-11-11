from collections import Counter
n = int(input())
class_a = [int(x) for x in input().split()]
class_b = [int(x) for x in input().split()]
A = Counter(class_a)
B = Counter(class_b)
delta = 0
for grade in range(1, 6):
	if (A[grade] + B[grade]) % 2 == 1:
		print(-1)
		exit()
	delta += abs(A[grade] - B[grade])
print(delta / 2)
