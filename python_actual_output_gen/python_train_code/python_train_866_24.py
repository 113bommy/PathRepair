a=int(input())
b=int(input())
c=int(input())
d=[]
for i in range(1,a+1):
    if(2*i<b and 4*i<c):
        d.append(i*7)
if(len(d)==0):
    print(0)
else:
    print(max(d))