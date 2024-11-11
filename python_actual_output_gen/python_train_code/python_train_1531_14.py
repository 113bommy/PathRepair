n = int(input())
x = input().split(" ")
s,t = map(int,input().split())

dist2 = 0
dist3 = 0


if s > t:
	for i in range(s-1,len(x)):
		dist2+=int(x[i])
	for i in range (0,t-1):
		dist2+=int(x[i])
	for i in range (t-1,s-1):
		dist3+=int(x[i])
if s < t:
	for i in range(t-1,len(x)):
		dist2+=int(x[i])
	for i in range (0,s-1):
		dist2+=int(x[i])
	for i in range (s-1,t-1):
		dist3+=int(x[i])

if s == t:
	print(0)
if dist2<=dist3:
	print(dist2)
else:
	print(dist3)
