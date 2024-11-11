n,s = map(int,input().split(" "))
elements = list(map(int,input().split(" ")))
elements.sort()
index = ((n+1)//2) - 1
median = elements[index]
moves = 0
#print("median: ",median)

def greater(elements,s,index):
	answer = 0
	while index != -1:
		toAdd = elements[index] - s
		if toAdd == 0:
			return answer
		answer += toAdd
		index -= 1 
	return answer

def smaller(elements,s,index,n):
	answer = 0
	while index != n:
		toAdd = s - elements[index]
		if toAdd == 0:
			return answer
		answer += toAdd
		index += 1 
	return answer

if median == s:
	print(0)
	exit()
if median > s:
	print(greater(elements,s,index))
	exit()
print(smaller(elements,s,index,n))



