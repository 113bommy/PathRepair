for t in range(int(input())):
    n, k = map(int,input().split())
    arr = list(map(int,input().split()))
    arr.sort()
    num = [10**arr[i] for i in range(n)]
    if arr[0] !=0:
        print(1)
        continue
    s = ''
    maxd = []
    for i in range(n-1):
        dd = arr[i+1]-arr[i]
        el = '9'*dd
        maxd += [int(el)]
    # print(maxd)
    # print(arr)

    money = 0
    for i in range(len(maxd)):
        if maxd[i] >k:
            diff = k + 1
            money += (diff*(10**arr[i]))
            k = 0
            break
        else:
            money += maxd[i]*(10**arr[i])
            k-= maxd[i]
    if k > 0:
        k += 1
        money += k*(10**arr[-1])
    print(money)




