for _ in range(int(input())):
    n = int(input())
    info = []
    for i in range(n):
        l, r = map(int, input().split())
        info.append([l-r, l, r])
    info.sort()
    mySet = set()
    ans = []
    for i in range(n):
        difference, l, r = info[i]
        for j in range(l, r+1):
            if j not in mySet:
                ans.append([l, r, j])
                mySet.add(j)
                break
    for i in ans: print(*i)