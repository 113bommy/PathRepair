# @Author: Justin Hershberger
# @Date:   06-04-2017
# @Filename: 412A.py
# @Last modified by:   Justin Hershberger
# @Last modified time: 06-04-2017



#Justin Hershberger
#Py3.5

import fileinput

def test():
	pass
if __name__ == '__main__':
	num_args = 2
	for arg in range(num_args):
		if arg == 0:
			n,k = map(int, input().split())
		else:
			slogan = input()

	if k != 1 and k != n:
		dist = min(abs(k-n), abs(k))
		if dist == k:
			while k != 1:
				k -= 1
				print("LEFT")
			for i in range(1,n+1):
				print("PRINT", slogan[i-1])
				if i < n:
					print("RIGHT")
		else:
			while k != n:
				k += 1
				print("RIGHT")
			for i in range(n, 0, -1):
				print("PRINT", slogan[i-1])
				if i > 1:
					print("LEFT")
	else:
		if k == 1:
			for i in range(1,n+1):
				print("PRINT", slogan[i-1])
				if i < n:
					print("RIGHT")
		else:
			for i in range(n,0,-1):
				print("PRINT", slogan[i-1])
				if i > 1:
					print("LEFT")
