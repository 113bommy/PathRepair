# import sys
# sys.stdin=open("input.in","r")
n=int(input())
l=[]
for i in range(n):
	l.append(1)
	while (len(l)>=2 and l[-1]==l[-2]):
		l.pop()
		l[-1]+=1
print("".join(map(str,l))) 