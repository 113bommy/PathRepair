input=__import__('sys').stdin.readline
ans='NO'
cs=0
for i in range(int(input())):
	a,b=map(int,input().split())
	if a==b:cs+=1
	else:cs=0
	if cs>=3:ans='YES'
print(ans)