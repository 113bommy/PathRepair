for _ in range(int(input())):

    n = int(input())
    l = []
    for x in range(n):
        l1 = list(map(int, input().split()))
        l.append(l1)

    if n == 1:
        print(1)
        continue

    champ = 0
    for x in range(1, n):
        temp = 0
        for y in range(5):
            if l[x][y] < l[champ][y]:
                temp += 1
        if temp >= 3:
            champ = x
    # print(champ)
    ans = 0
    for x in range(n):
        if x != champ:
            temp = 0
            for y in range(5):
                if l[x][y] < l[champ][y]:
                    temp +=1
            if temp >= 3:
                ans = -1
                print(ans)
                break
    else:
        print(champ + 1) 
