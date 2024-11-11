# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
x=int(input())
y=input()
count1=y.count('FS')
count2=y.count('SF')
if(count2>count1):
	print("YES")
else:
	print("NO")
