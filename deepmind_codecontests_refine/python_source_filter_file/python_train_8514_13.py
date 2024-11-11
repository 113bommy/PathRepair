import sys

s = input()
t = list(input())

string = s
length = 1

for i in range(len(t)):
	if s.find(t[i])==-1:
		print(-1)
		sys.exit()
	if string.find(t[i])==-1:
		string = string + s
		length += 1
	string = string[string.find(t[i])+1 : ]
	
print(length*len(s)-len(string))