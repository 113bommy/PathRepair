class Dice():
	def __init__(self, label):
		self.d = label
	
	def roll(self, drt):
		if drt == 'N':
			self.d[1], self.d[2], self.d[6], self.d[5] = self.d[2], self.d[6], self.d[5], self.d[1]
		elif drt == 'E':
			self.d[1], self.d[3], self.d[6], self.d[4] = self.d[4], self.d[1], self.d[3], self.d[6]
		elif drt == 'S':
			self.d[2], self.d[6], self.d[5], self.d[1] = self.d[1], self.d[2], self.d[6], self.d[5]
		elif drt == 'W':
			self.d[4], self.d[1], self.d[3], self.d[6] = self.d[1], self.d[3], self.d[6], self.d[4]
	
	def printl(self, lct):
		print(self.d[lct])
	
	def rot(self, drc):
		self.roll('N')
		if drc == 'r':
			self.roll('E')
		elif drc == 'l':
			self.roll('W')
		self.roll('S')
		
label = [0]	
label.extend(list(map(int, input().split())))
dice1 = Dice(label)
q = int(input())

ST = 'NNNNEEE'
SF = 'rrr'

for i in range(q):
	s = list(map(int, input().split()))
	for j in range(7):
		if dice1.d[1] == s[0]:
			break
		dice1.roll(ST[j])
	for k in range(3):
		if dice1.d[2] == s[1]:
			break
		dice1.rot(SF[k])
	dice1.printl(3)