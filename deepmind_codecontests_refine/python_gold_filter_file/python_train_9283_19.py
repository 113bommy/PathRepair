n = int(input())

if n%2 == 0:
    print("NO")
else:
    l = [i+1 for i in range(2*n+1)]
    print("YES")
    res = [0]*(2*n)
    is_max = False
    for i in range(n):
        if not is_max:
            res[i] = l[i]
            res[i+n] = l[i+1]
            is_max = True
        else:
            res[i] = l[-(i+1)]
            res[i+n] = l[-(i+2)]
            is_max = False
    print(*res)
    
    
    
