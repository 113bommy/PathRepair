n=input()
a=input().split()
one=0
two=0
res=0
for i in range(0,len(a)):
	if int(a[i]) == 1: one+=1
	else: two+=1
if one>two:
	res+=two
	one-=two
	res+=int(one/3)
elif one<two:res+=one
else: res+=one
print(res)