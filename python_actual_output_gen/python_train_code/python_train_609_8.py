a=list(map(int,input().split()))
a.sort()
if a[0]==0 and a[1]<=a[2]/2:
    print(a[1])
    exit()
elif a[0]==0:
    print(a[2] - a[1] + (2*(2*a[1] - a[2] ))//3)
    exit()
if (sum(a) - a[2]<=a[2]/2):
    print(a[0] + a[1])
    exit()
k=a[2]
a[2]-=sum(a)%3
k=k-a[2]
x=(a[2]+a[0]-2*a[1])//3
y=(a[2]+a[1]-2*a[0])//3
#print(x,y)
#print(x , y)
a[0]-=x
a[2]=a[1]=a[0]
#print(a)
if a[2]%3!=1:
    print(x + y + a[2])
elif k!=0:
    print(x + y + a[0])
elif x<0:
    print(x + y + a[0])
else:
    print(x + y + a[0] - 1)
#print(k)