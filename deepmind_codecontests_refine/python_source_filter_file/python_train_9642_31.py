# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
x=int(input())
y=input()
count1=y.count('FS')
count2=y.count('SF')
if(count1>count2):
	print("YES")
else:
	print("NO")
