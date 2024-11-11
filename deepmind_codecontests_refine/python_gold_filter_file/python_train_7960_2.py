m=int(input())
n=int(input())
ans=""
dic={2:"2",3:"3",4:"322",5:"5",6:"53",7:"7",8:"7222",9:"7332"}
x=str(n)
for i in range(len(x)):
	if(x[i]!='1' and x[i]!='0'):
		ans+=dic[int(x[i])]
a=[]
a.extend(ans)
for i in range(len(a)):
	a[i]=int(a[i])
a.sort()
for i in range(len(a)-1,-1,-1):
	print(a[i],end='')