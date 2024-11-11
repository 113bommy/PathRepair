I = input
for _ in [0]*int(I()):
	I();my_list = list(map(int,I().split()))
	if(sum(x for x in my_list if x < 2049) > 2048):
		print("YES")
	else:
		print("NO")



