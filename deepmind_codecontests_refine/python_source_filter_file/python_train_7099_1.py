
for _ in range(int(input())):
    n = int(input())
    kids = list(map(int, input().split()))
    
    res = [None] * n
    
    for i in range(n):
        if res[i] == None:
            idx = i
            clc = [i]
            num = 1
            while kids[idx] != i+1:
                idx = kids[idx]-1
                clc.append(idx)
                num += 1
            for j in clc:
                res[j] = num
    print(res)