t = int(input())
for u in range(t):
    m = int(input())
    s1 = list(map(int, input().split()))
    s2 = list(map(int, input().split()))
    if m == 2:
        print(0)
    else:
        pr1 = []
        su1 = 0
        for i in range(m):
            su1 += s1[i]
            pr1.append(su1)
        pr2 = []
        su2 = 0
        for i in range(m):
            su2 += s2[i]
            pr2.append(su2)
        mans = sum(s1) + sum(s2) 
        for i in range(m):
            if i == 0:
                tans = pr1[-1] - pr1[0]
            elif i == m - 1:
                tans = pr2[m - 2]
            else:
                tans = max(pr2[i - 1], pr1[-1] - pr1[i])
            mans = min(tans, mans)
        print(mans)
        
        