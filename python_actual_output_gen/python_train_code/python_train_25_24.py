l=int(input())
p=input().split()
l1=[1]
l2=[10**6]
for i in range(l):
	if(int(p[i])>55555):
		l2.append(int(p[i]))
	else:
		l1.append(int(p[i]))
print(max(max(l1)-min(l1) , 10**6-min(l2)))