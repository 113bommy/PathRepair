



if __name__ == '__main__':
    n ,w, b= [int(s) for s in input().split(" ")]
    arr=list(map(int, input().split()))
    l=len(arr)
    cost=0
    if w<=b:
        min=w
        max=b
    else:
        min=b
        max=w
    if l%2==0:
        for i in range(int(l/2)):
            if arr[i]==1 or arr[i]==0:
                if arr[l-1-i]!=2:
                    if arr[l-1-i]!=arr[i]:
                        print (-1)
                        exit(0)
                elif arr[l-1-i]==2:
                    if arr[i]==1:
                        cost+=b
                    elif arr[i]==0:
                        cost+=w
            else:
                if arr[l-1-i]==1:
                    cost+=b
                if arr[l-1-i]==0:
                    cost+=w
                elif arr[l-1-i]==2:
                    cost+=2*min
    if l%2==1:
        if arr[int(l/2)]==2:
            cost+=min
        for i in range(int(l / 2)):
            if arr[i] == 1 or arr[i] == 0:
                if arr[l - 1 - i] != 2:
                    if arr[l - 1 - i] != arr[i]:
                        print(-1)
                        exit(0)
                elif arr[l - 1 - i] == 2:
                    if arr[i] == 1:
                        cost += b
                    elif arr[i] == 0:
                        cost += w
            else:
                if arr[l - 1 - i] == 1:
                    cost += b
                if arr[l - 1 - i] == 0:
                    cost += w
                elif arr[l - 1 - i] == 2:
                    cost += 2*min

    print (cost)


