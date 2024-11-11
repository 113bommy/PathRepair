def list_input(data):
	return list(map(data, input().strip().split()))

def single_input(data):
	return map(data, input().strip().split())

arg = int(input()) 
l1 = [0] + list_input(int)

e = 0
res = 0
for i in range(0, arg-1):  

	e += (l1[i] - l1[i+1])

	if e < 0:
		res += e* -1  

	e = 0

print(res)