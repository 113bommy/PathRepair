for _ in range(int(input())):
    n = int(input())
    odd = 0
    even = 0
    step = 0
    arr = list(map(int,input().split()))
    for i in range(0,n):
        if(i%2!=0):
            if(arr[i]%2!=0):
                continue
            else:
                if(even!=0):
                    step+=1
                    even-=1
                else:
                    odd = +1
        else:
            if(arr[i]%2==0):
                continue
            else:
                if(odd!=0):
                    step+=1
                    odd -= 1
                else:
                    even = 1
    if(even!=0 or odd!=0):
        step = -1
    print(step)