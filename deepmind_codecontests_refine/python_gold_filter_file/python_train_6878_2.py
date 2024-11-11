# coding: utf-8
# ?????????????????¨????????????
class Dice(object):
	def __init__(self):
		# ????????¶???
		self.dice = (2, 5), (3, 4), (1, 6) # x, y, z
		self.ax = [[0, False], [1, False], [2, False]]
		self.axmap = [0, 1, 2]
		self.mm = {"N": (0, 2), "S": (2, 0), "E": (1, 2), "W": (2, 1), "R": (0, 1), "L": (1, 0)}

	def rotate(self, dir):
		def rot(k, r):
			t = self.axmap[r]
			self.axmap[k], self.axmap[r] = t, self.axmap[k]
			self.ax[t][1] = not self.ax[t][1]

		rot(*self.mm[dir])

	def front(self): return self.value(0, True)
	def rear(self): return self.value(0, False)
	def right(self): return self.value(1, True)
	def left(self): return self.value(1, False)
	def top(self): return self.value(2, True)
	def bottom(self): return self.value(2, False)
	def value(self, ax, d):
		a = self.ax[self.axmap[ax]]
		return self.dice[a[0]][a[1] if d else not a[1]]

if __name__=="__main__":
	dice = Dice()
	labels = input().split()
	q = int(input())
	def tf(p, f, d):
		for _ in range(4):
			if p==f(): break
			dice.rotate(d)

	for _ in range(q):
		a, b = input().split()
		p = labels.index(a) + 1
		f = dice.top
		tf(p, f, "N")
		tf(p, f, "E")
		
		p = labels.index(b) + 1
		f = dice.front
		tf(p, f, "R")

		print(labels[dice.right()-1])