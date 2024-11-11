n=list(map(int,input().split()))
t=list(map(int,input().split()))
s=(n[0]-1)*10
r=s
flag=1
for i in range(len(t)):
        s+=t[i]
        if(s>n[1]):
            flag=0
            break
if(flag==0):
	print("-1")
else:
	print((r//5)+(n[1]-s)//5)
	
            