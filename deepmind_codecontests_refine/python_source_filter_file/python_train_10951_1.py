t = int(input())
while t > 0:
    t = t-1
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    d = dict()
    temp = [(a[i]-b[i]) for i in range(n)]
    for i in temp:
        if i in d:
            d[i] +=1
        else:
            d[i] = 1
    
    if len(d) > 2:
        print("NO")
    elif len(d) == 1:
        if a[0] <= b[0]:
            print("YES")
        else:
            print("NO")
    else:
        c = 0
        diff = -1
        for k,v in d.items():
            if k != 0:
                diff = k
            else:
                c = 1
        if c == 0 or diff > 0:
            print("NO")
        else:
            l = temp.index(diff)
            c = 0
            r = 0
            for i in range(l,n):
                if temp[i] != temp[l]:
                    r = i-1
                    break
            
            
            val = r-l+1
            if d[diff] == val:
                print("YES")
            else:
                print("NO")