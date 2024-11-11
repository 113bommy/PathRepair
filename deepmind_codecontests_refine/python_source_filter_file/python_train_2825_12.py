class CustomException(Exception): pass

def main():
	n = int(input())
	x = n//4
	y = n//7
	try:
		for i in reversed(range(x+1)):
			for j in range(y+1):
				if (4*i+7*j==n):
					print('4'*i, '7'*j, sep='')
					raise CustomException
				elif (4*i+7*j>n):
					break
	except CustomException as err:
		pass
	else:
		print('-1')


if __name__ == '__main__':
	main()

