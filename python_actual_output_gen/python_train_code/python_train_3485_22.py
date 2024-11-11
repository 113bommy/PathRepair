for i in range(int(input())):
    n = int(input())
    l  =[]
    for i in range(n):
        l.append(input())
    res = {}
    flag = 0
    for i in l:
        for keys in i:
            res[keys] = res.get(keys, 0) + 1
    for i in res.values():
        if(i%n!=0):
            flag = 0
            break
    if(flag==0):
        print("YES")
    else:
        print("NO")