# @Author: Justin Hershberger
# @Date:   23-03-2017
# @Filename: 399A.py
# @Last modified by:   Justin Hershberger
# @Last modified time: 23-03-2017



#Justin Hershberger
#Py3.5

import fileinput

def test():
	pass
if __name__ == '__main__':
	n,p,k = map(int, input().split())

	output = ""

	if p - k > 0:
		output = "<< "

	for i in range(p-k,p+k+1):
		if i == p:
			output += "(" + str(i) + ") "
		elif i > n:
			break
		elif i > 0:
			output += str(i) + " "

	if p + k < n:
		output += ">>"

	print(output)
