# your code goes here
# your code goes here
n,m=input().split()
n=int(n)
m=int(m)
l=[]
for i in range(n):
	l.append(input())
s=input()
lc=0#counts less length strings
ec=0#counts equal length strings:
for i in l:
	if(len(i)<len(s)):
		lc=lc+1
	if(len(i)==len(s)):
		ec=ec+1
bt=0#best case time
wt=0#worst case time
for i in range(lc):
	if((i+1)%m==0):
		bt=bt+6
	else:
		bt=bt+1
for i in range(lc+ec):
	if((i+1)%m==0):
		wt=wt+6
	else:
		wt=wt+1
print(bt+1,wt)

