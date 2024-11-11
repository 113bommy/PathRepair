def check(arr):
    arr.sort()
    a=sum(arr)/len(arr)
    b=(arr[1]+arr[2])/2
    c=arr[-1]-arr[0]

    return a==b==c

n=int(input())

arr=[int(input()) for i in range(n)]
arr.sort()

if n==0:
    print("YES")
    print(1)
    print(1)
    print(3)
    print(3)
elif n==4:
    if check(arr):
        print("YES")
    else:
        print("NO")
elif n==2:
    if 3*arr[0]<arr[1]:
        print("NO")
    else:
        print("YES")
        print(4*arr[0]-arr[1])
        print(3*arr[0])
elif n==3:
    if 3*arr[0]<arr[2]:
        print("NO")
    else:
        if check([arr[0],arr[1],arr[2],3*arr[0]]):
            print("YES")
            print(3*arr[0])
        elif check([arr[2]/3,arr[0],arr[1],arr[2]]):
            print("YES")
            print(arr[2]/3)
        elif check([arr[0],arr[1],arr[0]+arr[2]-arr[1],arr[2]]):
            print("YES")
            print(arr[0]+arr[2]-arr[1])
        else:
            print("NO")
elif n==1:
    print("YES")
    print(arr[0])
    print(arr[0]*3)
    print(arr[0]*3)
