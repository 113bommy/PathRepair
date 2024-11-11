w,h = map(int,input().split())
u1,d1 = map(int,input().split())
u2,d2 = map(int,input().split())
s = w
for i in range(h,0,-1):
	if s < 0:
		break
	s = s + i
	if i == d1:
		s = s - u1
	elif i == d2:
		s = s - u2
if s<0:
	s = 0
print(s)