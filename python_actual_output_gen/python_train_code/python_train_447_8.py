line1 = input()
line1 = line1.split()
k = int(line1[0])
bef = int(line1[1])
aft = int(line1[2])

line2 = input()
line2 = line2.split()

line2 = list(map(int, line2))

length = len(line2) 
line2 = [2*(10**9)]*bef + line2 + [2*(10**9)]*aft

for i in range(length):
	el = line2[bef+i]
	if all(list(map(lambda x: x>el, line2[i:bef+i]))) and all(list(map(lambda x: x>el, line2[bef+i+1:bef+aft+i]))):
		print(i+1)
		break 
