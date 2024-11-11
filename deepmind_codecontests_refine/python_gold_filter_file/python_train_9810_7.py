t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    if len(s)==1:
        print(s)
        print(1)
        continue
    res = []
    for k in range(0, n):
        ss = s
        if (n-k) % 2 == 1:
            ss = ss[k:] + ss[:k][::-1]
        else:
            ss = ss[k:] + ss[:k]
        res.append((ss, k+1))

    res.sort()
    
    print(res[0][0])
    print(res[0][1])
    
