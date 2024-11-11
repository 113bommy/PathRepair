n = int(input())

Apples = {}
leftTrees = []
rightTrees = []
sums = 0

for i in range(n):
	x, Apple = map(int, input().split())
	Apples[x] = Apple
	if (x < 0):
		leftTrees.append(x)
	else:
		rightTrees.append(x)

leftTrees.sort()
rightTrees.sort()


if (len(rightTrees) > len(leftTrees)) :
	for i in range(len(leftTrees)):
		sums += Apples[leftTrees[i]]
		sums += Apples[rightTrees[i+1]]
	sums += Apples[rightTrees[0]]

if (len(rightTrees) < len(leftTrees)) :
	for i in range(0,len(rightTrees)):
		sums += Apples[leftTrees[len(leftTrees)-i-2]]
		sums += Apples[rightTrees[i]]
	sums += Apples[leftTrees[len(leftTrees)-1]]
	

if (len(rightTrees) == len(leftTrees)) :
	for i in range(0,len(rightTrees)):
		sums += Apples[leftTrees[i]]
		sums += Apples[rightTrees[i]]

print(sums)