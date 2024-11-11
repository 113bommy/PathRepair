T = int(input())
inputs=[]
while(T!=0):
	n = int(input())
	inputs.append(n)
	T-=1

def largestnumber(n):
	digits = []

	left = n
	
	while left>1:

		if left==3:
			digits.append('7')
			left=left-3
		else:
			digits.append('1')
			left = left - 2

	print(''.join(digits))


def main():
	if 1<=len(inputs)<=100:
		for x in inputs:
			if 2<=x<=10**5:
				largestnumber(x)

main()