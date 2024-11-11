def add(s):
	ans.append((s[0]+1,s[1]+1))
	ans.append((s[0]+2,s[1]))
	ans.append((s[0]+3,s[1]))
	ans.append((s[0]+2,s[1]+1))
	ans.append((s[0]+2,s[1]+2))
	ans.append((s[0]+3,s[1]+1))
	ans.append((s[0]+3,s[1]+2))
	ans.append((s[0]+4,s[1]+1))
	return [s[0]+4,s[1]]

def addone(s):
	ans.append((s[0]+1,s[1]))
	ans.append((s[0]+1,s[1]+1))
	ans.append((s[0]+1,s[1]+2))
	ans.append((s[0]+2,s[1]))
	ans.append((s[0]+2,s[1]+1))
	ans.append((s[0]+2,s[1]+2))
	return [s[0]+3,s[1]+1]

def joinends(s):
	ans.append((0,1))
	ans.append((0,2))
	ans.append((0,3))
	ans.append((0,4))
	for i in range(1,s[0]+2):
		ans.append((i,4))
	ans.append((s[0]+1,3))
	ans.append((s[0]+1,2))
	ans.append((s[0]+1,1))


n = int(input())
if n==1:
	print (7)
	print (0,0)
	print (0,1)
	print (1,0)
	print (1,1)
	print (1,2)
	print (2,1)
	print (2,2)
	exit()
ans = []
s = [0,0]
for i in range(n//2):
	s = add(s) 
s[1] += 1
joinends(s)
if n%2:
	ans.append((s[0]+1,5))
	ans.append((s[0]+2,4))
	ans.append((s[0]+2,5))

print (len(ans))
for i in ans:
	print (i[0],i[1])