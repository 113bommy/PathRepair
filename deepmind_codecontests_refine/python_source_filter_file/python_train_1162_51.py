import sys
try:    
	sys.stdin = open('inp.txt', 'r')
except: pass

def helper():
	# write code from here
	pass
################################

n = int(input())
a = (4 * n) + 1
b = (4 * n) + 3
c = (4 * n) + 2
d = (4 * n)

if n % 4 == 1:
	print (0,'A')

elif n % 4 == 0 :
	print (1 , 'C')

elif n % 4 == 2 :
	print (1 , 'B')
elif n % 4 == 3 :
	print (2, 'A')