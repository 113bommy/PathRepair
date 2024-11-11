l = list(map(int, input().split(" ")))
najv = l.index(max(l))

odpoved = l[najv]
for i in range(len(l)):
	if l[i] != l[najv]:
		odpoved -= l[i]
		
if odpoved >= 0:
	print(odpoved+1)
	
else:
	print(0)
	