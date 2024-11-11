# AOJ 0087 Strange Mathematical Expression
# Python3 2018.6.14 bal4u

class Stack:
	def __init__(self):
		self.items = []
	def push(self, item):
		self.items.append(item)
	def pop(self):
		return self.items.pop()
	def size(self):
		return len(self.items)

s = Stack()
while True:
	try:
		a = list(input().split())
	except EOFError:
		break

	for token in a:
		if token in ['+','-','*','/']:
			v1, v2 = s.pop(), s.pop()
			if token == '+':
				v2 += v1
			elif token == '-':
				v2 -= v1
			elif token == '*':
				v2 *= v1
			else:
				v2 /= v1
			s.push(v2)
		else:
			s.push(int(token))
print(s.pop())

