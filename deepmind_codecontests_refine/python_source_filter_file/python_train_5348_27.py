import re


def bigBinary(bino):
	if '0' in bino:
		return re.sub('0', '', bino)
	return bino[1:]

if __name__ == '__main__':
	print(bigBinary((input())))