s,a=set(map(int,input().split(','))),''
l=[x for x in s]
l.sort
for i in l:
	if i-1 not in l:a+=','+str(i)
	elif i+1 not in l:a+='-'+str(i)
print(a[1:])
