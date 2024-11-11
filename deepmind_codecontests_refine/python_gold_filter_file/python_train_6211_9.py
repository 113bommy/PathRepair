import re

math = re.compile('\((\d+)\+(\d+)\)\/(\d+)')
d1 = dict()
d2 = dict()

def main():
	n = int(input())

	for i in range(n):
		string = input()
		match = math.match(string)
		a = int(match.group(1))
		b = int(match.group(2))
		c = int(match.group(3))
		d2[i+1]=((a+b)/c)
		try :
			d1[((a+b)/c)]+=1
		except:
			d1[((a+b)/c)]=1

	lis = []

	for i in range(n):
		lis.append(str(d1[d2[i+1]]))

	print(' '.join(lis))


if __name__ == '__main__':
	main()
