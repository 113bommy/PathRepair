x,y,z=map(int,input().split())
x1=[1,x]
x2=[2,y]
x3=[3,z]
arr=[x1,x2,x3]
a=0
b=0
x=0
c=0
arr=sorted(arr, key = lambda x: x[1])

while 1:
    arr=sorted(arr, key = lambda x: x[1])
    # print(arr)
    if arr[2][1]<2:
        break
    i=0
    while 1:
        if 2**i>arr[0][1]:
            break
        i+=1
    i=i-1
    if arr[0][1]>0 and i>0:
        arr[0][1]-=2**(i-1)
        arr[1][1]-=2**(i-1)
        arr[2][1]-=2**i
        if arr[2][0]==1:
            a+=2**(i-1)
            c+=2**(i-1)
        elif arr[2][0]==2:
            a+=2**(i-1)
            b+=2**(i-1)
        elif arr[2][0]==3:
            b+=2**(i-1)
            c+=2**(i-1)
    elif arr[0][1]>0 and i==0:
        arr[0][1]-=1
        arr[1][1]-=1
        arr[2][1]-=2
        if arr[2][0]==1:
            a+=1
            c+=1
        elif arr[2][0]==2:
            a+=1
            b+=1
        elif arr[2][0]==3:
            b+=1
            c+=1
    elif arr[1][1]==arr[2][1] and arr[0][1]<=0:
        x=arr[1][1]
        arr[1][1]=0
        arr[2][1]=0
        if (arr[2][0]==1 and arr[1][0]==2) or (arr[2][0]==2 and arr[1][0]==1):
            a+=x
        elif (arr[2][0]==2 and arr[1][0]==3) or (arr[2][0]==3 and arr[1][0]==2):
            b+=x
        elif (arr[2][0]==3 and arr[1][0]==1) or (arr[2][0]==1 and arr[1][0]==3):
            c+=x
    else:
        print("Impossible")
        exit()
if arr[0][1]==0 and arr[1][1]==0 and arr[2][1]==0:
    print(a,b,c)
elif arr[0][1]==0 and arr[1][1]==0 and arr[2][1]==1:
    print("impossible")
elif arr[0][1]==0 and arr[1][1]==1 and arr[2][1]==1:
    if (arr[2][0]==1 and arr[1][0]==2) or (arr[2][0]==2 and arr[1][0]==1):
        a+=1
    elif (arr[2][0]==2 and arr[1][0]==3) or (arr[2][0]==3 and arr[1][0]==2):
        b+=1
    elif (arr[2][0]==3 and arr[1][0]==1) or (arr[2][0]==1 and arr[1][0]==3):
        c+=1
    print(a,b,c)
elif arr[0][1]==1 and arr[1][1]==1 and arr[2][1]==1:
    print("impossible")

    

