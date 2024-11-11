import sys

def input():
	return sys.stdin.readline().rstrip()

def input_split():
	return [int(i) for i in input().split()]

testCases = int(input())
answers = []
for _ in range(testCases):
	#take input
	x1, y1, z1 = input_split()
	x2, y2, z2 = input_split()
	ans = 0
	if z1 > y2:
		ans += y2
		up_anni = x1 + (z1 - y2)

		if up_anni > z2:
			#khatam 
			pass
		else:
			ans -= z2 - up_anni
	else:
		ans += z1
		up_anni = y2 - z1

		if up_anni > z2:
			#khatam 
			pass
		else:
			ans -= z2 - up_anni

	answers.append(2*ans)

print(*answers, sep = '\n')
