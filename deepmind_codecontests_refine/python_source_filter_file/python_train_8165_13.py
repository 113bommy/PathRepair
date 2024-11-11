n = input()
t =[0]*100001
for i in map(int,input().split()):
	t[i] += i
a = b = 0
for r in t:
	a,b = max(a,b), a + r
print(a)