maxPoints = int(input())
students = input().split(" ")
students = [int(x) for x in students]
limits = input().split(" ")
x = int(limits[0])
y = int(limits[1])
for i in range(1, maxPoints):
	beginner = 0
	for j in range(0, i):
		beginner += students[j]
	inter = 0
	for j in range(i, maxPoints):
		inter += students[j]
	if x <= beginner <= y and x <= inter <= y:
		print(i+1)
		exit(0)
print(0)