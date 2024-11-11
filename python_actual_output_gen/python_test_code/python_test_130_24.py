# import sys
# sys.stdin=open("input.in","r")
a=input()
b=input()
j=0
for i in range(len(b)):
	if a[i]==b[j]:
		j+=1
print(j+1)