# your code goes here
t = int(input())
for val in range(t):
	s = input()
	last = s[len(s)-1]
	if(last == 'o'):
		print("FILIPINO")
	elif(last == 'u'):
		print("JAPANISE")
	elif(last == 'a'):
		print("KOREAN")