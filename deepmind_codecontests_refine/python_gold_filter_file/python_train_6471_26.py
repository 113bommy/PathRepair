import os
k = int(input()) 
string = ""
i=0
while len(string)<k:
	i=i+1
	string=string+str(i)
print(string[k-1])