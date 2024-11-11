n = int(input())
a = list(map(str,input().split()))

data1 = a[:]
data2 = a[:]

def bubble_sort(data):
	for i in range(len(data)):
		for j in range(len(data)-1,i,-1):
			if(data[j][1] < data[j-1][1]):
				data[j],data[j-1] = data[j-1],data[j]

	return(data)

def selection_sort(data):
	for i in range(len(data)):
		minj = i
		for j in range(i,len(data)):
			if(data[j][1] < data[minj][1]):
				minj = j

		data[i],data[minj] = data[minj],data[i]

	return(data)
data1 = bubble_sort(data1)
data2 = selection_sort(data2)
print(*data1)
print("Stable")
print(*data2)
print("Stable" if data1 == data2 else "Not stable")

