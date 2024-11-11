

N = int(input())

list = []

def function(Integer):
	if(Integer % 2 == 0):
		return((Integer/2)*(Integer/2-1)/2)

	else:
		a = (Integer+1)/2
		return((a*(a-1)/2)+(a-1)*(a-2)/2)

for i in range(N):
	list.append(input())

dict = {}

for i in list:
	dict[i[0]] = 0


for i in list:
	dict[i[0]] += 1


count = 0

for i in dict:
	count += function(dict[i])

print(int(count))