a=list(map(int,input().split(':')))
a[1]+=int(input())
if a[1]>=60:
	a[0]+=a[1]//60
	a[1]%=60
if a[0]>=24:a[0]%=24
print(str(a[0]).zfill(2),':',str(a[1]).zfill(2),sep='')