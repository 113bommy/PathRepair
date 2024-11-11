# -*- coding:shift-jis -*-

class Dice:

	def __init__(self):
		self.top = 1
		self.south = 2
		self.north = 5
		self.east = 3
		self.west = 4
		self.bottom = 6

	def rotate(self,operation):
		if operation == "North":
			self.top,self.north,self.bottom,self.south = self.south,self.top,self.north,self.bottom
		elif operation == "East":
			self.top,self.east,self.bottom,self.west = self.west,self.top,self.east,self.bottom
		elif operation == "West":
			self.top,self.east,self.bottom,self.west = self.east,self.bottom,self.west,self.top
		elif operation == "South":
			self.top,self.north,self.bottom,self.south = self.north,self.bottom,self.south,self.top
		elif operation == "Right":
			self.north,self.east,self.south,self.west = self.west,self.north,self.east,self.south
		elif operation == "Left":
			self.north,self.east,self.south,self.west = self.east,self.south,self.west,self.north,

n = int(input()[0])

while n!=0:
	inputs = [input() for _ in range(n)]
	value = 1
	d = Dice()
	for i in inputs:
		d.rotate(i)
		value += d.top
	print(value)
	n = int(input())