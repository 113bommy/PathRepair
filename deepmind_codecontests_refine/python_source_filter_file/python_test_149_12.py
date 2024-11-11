from math import ceil

t = int(input())
for _ in range(t):
    n,k,x = list(map(int,input().split()))
    s = input()

    if k == 0:
        print(s.replace("*",""))
        continue

    cnt = 0
    lst = []
    for c in s:
        if c == "a":
            if cnt:
                lst.append(cnt*k)
            lst.append("a")
            cnt = 0
        else:
            cnt += 1
    else:
        if cnt:
            lst.append(cnt*k)
    cnt = 1
    l = len(lst)
    flg = False
    for i in range(l-1,-1,-1):
        if lst[i] == "a":
            continue
        if flg:
            lst[i] = 0
            continue
        cnt *= (lst[i]+1)
        if cnt >= x:
            for j in range(i,l):
                if lst[j] == "a":
                    continue
                if x:
                    cnt //= (lst[j]+1)
                    lst[j] = ceil(x / cnt) - 1
                    x -= cnt * (lst[j] + 1)
            flg = True

    for i in range(l):
        if lst[i] == "a":
            continue
        lst[i] = "b"*lst[i]

    print("".join(lst))