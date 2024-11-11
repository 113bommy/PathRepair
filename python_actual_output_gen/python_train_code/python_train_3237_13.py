import sys;

def solve(input, k):
	if((input >= k) and (input > 0)):
		return True
	return False

if __name__ == '__main__':
	count = 0
	n = sys.stdin.readline()
	s = sys.stdin.read()
	s = s.split(" ")
	n = n.split(" ")
	print(s)

	for x in range(int(n[0])):
		if((solve(int(s[x]), int(s[int(n[1])-1])))):
			count+=1
	print(count)
