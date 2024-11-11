for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    zero = False
    np = 0
    pos = []
    nn = 0
    neg = []
    for i in range(n):
        if arr[i] > 0:
            np += 1
            pos.append(arr[i])
        elif arr[i] < 0:
            nn += 1
            neg.append(arr[i])
        else:
            zero = True
    pos.sort(reverse=True)
    neg.sort()
    ans = []
    for i in range(5):
        if np >= 5-i and nn >= i:
            temp = 1
            for j in range(5-i):
                temp *= pos[j]
            for j in range(i):
                temp *= neg[j]
            ans.append(temp)
    if nn >= 5:
        temp = 1
        for i in range(5):
            temp *= neg[i]
        ans.append(temp)
    if zero:
        ans.append(0)
    print(max(ans))
