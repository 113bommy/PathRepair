s = input().split(' ')
a = int(s[0])
b = int(s[1])
c = input()
dc = {}
for i in c:
	dc[i] = 0
for i in c:
	dc[i] += 1
bad = False
for i in dc:
	if(dc[i] > b):
		print("NO")
		bad = True
if(bad == False):
	print("YES")
