

def elego(arr) :

    minimum = min(arr)
    cnt = 0

    for i in range(1,n) :

        if minimum == arr[i] :

            cnt =cnt +1

            pos = i+1
    if cnt == 1 :

        print(pos)
    else :

        print("Still Rozdil")
    return

n = int(input())



a = [n for n in map(int,input().split())]

elego(a)