r=int(input())
y=0
x=1
cnt=0
while True:
    y=(r-1-x-x*x)/(2*x)
    s=int(y)
    if y<0:
        break
    if y==s:
        cnt=1
        break
    else:
        x+=1

if cnt==1:
    print(x,s)
else :
    print("NO")