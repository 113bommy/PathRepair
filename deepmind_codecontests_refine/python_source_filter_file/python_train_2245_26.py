#!/usr/bin/env python3

import fileinput
import sys

def main():
	length, jump = input('').split(" ")
	line2 = (input(''))
	length=int(length)
	jump=int(jump)

	position = line2.find("G")#G stands for grasshopper

	target = line2.find("T")


	#need a way to detect if we pass the target

	print(length, jump, position, target)


	if(target > position):
		while position != target:
			if((not(jump <= (length-1)-position)) or (line2[position+jump] == "#")):
				break
			else:
				position = position + jump
	elif(target < position):
		while position != target:
			if(not(jump <= position) or line2[position-jump] == "#"):
				break
			else:
				position = position - jump

	if(position == target):
		print("YES")
	else:
		print("NO")

if __name__ == '__main__':
	main()