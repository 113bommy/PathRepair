
class Pair:
	def __init__(self,x,y):
		self._data =_data =[x,y]
	def __setitem__(self, key, value):
		self._data[key] = value
	def __getitem__(self,key):
		return self._data[key]
	def __len__(self):
		return len(_data)
	def __repr__(self):
		return '{'+str(self._data[0])+','+str(self._data[1])+'}'
n,m = map(int,input().split())
v = []
d = dict()
for i in range(m):
	f,s = map(int,input().split())
	v.append(Pair(f,s))
value = [v[0][0],v[0][1]]
flag = False
for x in value:
	val = [0]*(n+1)
	a = 0
	for y in v:
		if y[0]!=x and y[1]!=x:
			a+=1
			val[y[0]]+=1
			val[y[1]]+=1
		print(x,val)
	if max(val) == a:
		print('YES')
		flag = True
		break
if not flag:
	print('NO')







