for case in range (int (input ())) :
    n, k = list (map (int, input ().split ()))
    a = list (map (int, input ().split ()))

    i = 0
    ans = []

    while i < n :
        if i > n - k :
            break
        s = 0
        while i < n and not (s & 1) :
            s += a[i]
            i += 1
        
        if not (s & 1):
            break

        ans.append(i)
        k -= 1
    
    flg = True if k == 0 and not (sum (a[i :]) & 1) else False
    if flg :
        ans[-1] = n
    
    print ("YES\n" + ' '.join (map (str, ans)) if flg else "NO")