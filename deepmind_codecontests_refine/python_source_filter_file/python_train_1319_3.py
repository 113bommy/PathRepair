'''input
4 2
'''

import sys

def function(a,b):
	prob = 6-max(a,b)+1
	if prob == 1 or prob==5: return f'{prob}/6'
	elif prob == 2 or prob==4: return f'{prob/2}/3'
	elif prob == 3: return '1/2'
	elif prob == 6: return '1/1'	

def main():
	a,b = map(int,sys.stdin.readline().split())
	res = function(a,b)
	print(res)


if __name__ == '__main__':
    main()
