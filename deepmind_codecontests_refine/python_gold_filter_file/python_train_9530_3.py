n=int(input())
l=[]
count=0
for i in range(n):
	w=list(map(str,input().split()))
	l.append(w)
for i in range(n):
	x=int(l[i][2])-int(l[i][1])
	if (x>0) and int(l[i][2])>2400 and int(l[i][1])>=2400:
		count+=1
if count>=1:
	print("YES")
else:
	print("NO")
