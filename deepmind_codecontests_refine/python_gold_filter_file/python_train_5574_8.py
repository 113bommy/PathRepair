


def start() :
    a = input().split()
    n = int(a[0])
    p = int(a[1])

    small1 = n
    large2 = 0

    arr = []
    for i in range(0, n):
        arr.append(0)
    pairs = []
    for i in range(0, p):
        pairs.append(input().split())


    if(n<2):
        print("0")


    for i in range(0, p):
        s = pairs[i]
        a1 = int(s[0])
        a2 = int(s[1])
        if(a1>a2):
            if(arr[a1-1]==2):
                print("0")
                return
            else:
                arr[a1-1] = 1
                if(small1>a1):
                    small1 = a1
            if(arr[a2-1]==1):
                print("0")
                return
            else:
                arr[a2-1] = 2
                if(large2<a2):
                    large2 = a2
        else:
            if(arr[a1-1]==1):
                print("0")
                return
            else:
                arr[a1-1] = 2
                if(large2<a1):
                    large2 = a1
            if(arr[a2-1]==2):
                print("0")
                return
            else:
                arr[a2-1] = 1
                if(small1>a2):
                    small1 = a2

    if(small1<=large2):
        print("0")
        return



    w = 1
    for i in range(0, n):
        if(arr[i]==0):
            if(small1>(i+1)):
                if(large2<(i+1)):
                    w += 1
    if(p==0):
        w -= 1
    print(str(w))


    return

start()