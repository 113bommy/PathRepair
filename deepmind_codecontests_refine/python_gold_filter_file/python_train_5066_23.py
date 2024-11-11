input()
a = list(map(int,input().split()))
b = list(map(int,input().split()))
i=0
dif=0
out = ''
for bi in b:
	while(bi>dif+a[i]):
		dif+=a[i]
		i+=1
	out+='%d %d\n'%(i+1,bi-dif)
print(out)