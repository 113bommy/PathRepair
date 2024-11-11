n = int(input())
a = list(map(int,input().split()))
x=y=0
for i in range(n-1):
    if a[i+1]<a[i]:
        x=i+1
        break
for i in range(n-1,0,-1):
    if a[i-1]>a[i]:
        y=i
        break
if x==0 and y==0:
    print("yes")
    print('1 1')
else:
    f=0
    for i in range(max(x-2,0),y):
        if a[i]<a[i+1]:
            f=1
            print("no")
            break
    if f==0 and (x==1 or y==n-1):
        if x==1:
            if y!=n-1:
                if a[0]<a[y+1]:
                    print("yes")
                    print(x,y+1) 
                else:
                    print("no")
            else:
                print("yes")
                print(x,y+1)
        else:
            if a[x-2]<a[n-1]:
                print("yes")
                print(x,y+1) 
            else:
                print("no")
    elif f==0 and a[x-2]<a[y] and a[x-1]<a[y+1]:
        print("yes")
        print(x,y+1)
    elif f==0:
        print("no")