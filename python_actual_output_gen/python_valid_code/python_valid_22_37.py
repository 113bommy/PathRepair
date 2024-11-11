n=int(input())
l=list(map(int,input().split()))
x=y=z=0
t=n%3
for i in range(0,n-t,3):
    x+=l[i]
    y+=l[i+1]
    z+=l[i+2]
if(t==1):
    x+=l[n-1]
elif(t==2):
    x+=l[n-2]
    y+=l[n-1]
if(x>=y and x>=z):
    print("chest")
elif(y>=x and y>=z):
    print("biceps")
else:
    print("chest")