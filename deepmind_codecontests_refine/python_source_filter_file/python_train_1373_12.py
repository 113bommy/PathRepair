class Point:
	def __init__(self):
		self.x = 0
		self.y = 0
	
	def __repr__(self):
		return f"({self.x}, {self.y})"
		

def covers(p1, p2, p3, p4):
	if p3.x <= p1.x and p2.x <= p4.x and p3.y <= p1.y and p2.y <= p4.y:
		return True
	return False

def splits(p1, p2, p3, p4):
	if p1.x <= p3.x < p2.x <= p4.x or p3.x <= p1.x < p4.x <= p2.x:
		if p3.y <= p1.y and p2.y <= p4.y:
			if p3.x <= p1.x:
				p1.x = p4.x
			else:
				p2.x = p3.x
			return True
	elif p1.y <= p3.y < p2.y <= p4.y or p3.y <= p1.y < p4.y <= p2.y:
		if p3.x <= p1.x and p2.x <= p4.x:
			if p3.y <= p1.y:
				p1.y = p4.y
			else:
				p2.y = p3.y
			return True
	return False

p1, p2, p3, p4, p5, p6 = [Point() for _ in range(6)]
p1.x, p1.y, p2.x, p2.y = map(int, input().split(' '))
p3.x, p3.y, p4.x, p4.y = map(int, input().split(' '))
p5.x, p5.y, p6.x, p6.y = map(int, input().split(' '))

if covers(p1, p2, p3, p4) or covers(p1, p2, p5, p6):
	print("NO")
else:
	if splits(p1, p2, p3, p4):
		if covers(p1, p2, p5, p6):
			print("NO")
		else:
			print("YES")
	else:
		print("YES")