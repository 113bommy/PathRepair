t = int(input())
power = ["Mind","Power","Reality","Soul","Space","Time"]
color = ["yellow","purple","red","orange","green","blue"]
present = [0]*6
for i in range(t):
	col = str(input().strip())
	if col in color:
		present[color.index(col)] = 1
print(6-sum(present))
for i in range(6):
	if not present[i]:
		print(power[i])