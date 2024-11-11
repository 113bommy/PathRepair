t = int(input())
for j in range(t):
    n, a, b = map(int, input().split())
    ans1 = 0
    ans2 = 0
    s = input()
    ch = 0
    per = ""
    e = 0
    for i in range(n):
        if ch == 1 and per != s[i]:
            if per == "1":
                ans1 += max(a*e+b, a*e+e*b)
            else:
                ans2 += max(a*e+b, a*e+e*b)
            e = 0
            ch = 0
            per = s[i]
        if ch == 1 and per == s[i]:
            e += 1
        if ch == 0:
            per = s[i]
            ch = 1
            e += 1
    if e != 0:
        if per == "1":
            ans1 += max(a*e+b, a*e+e*b)
        else:
            ans2 += max(a*e+b, a*e+e*b)
    #print(ans2)
    ed = s.count("1")
    nol = s.count("0")
    #print(ans1+nol*a+b)
    #print(ans1+nol*a+b*nol)
    #print( ans2+ed*a+b)
    #print(ans2+ed*a+b*ed)
    if ed == 0:
        print(max(ans1+nol*a+b, ans1+nol*a+b*nol, ans2))
    if nol == 0:
        print(max(ans1, ans2+ed*a+b, ans2+ed*a+b*ed))
    else:
        print(max(ans1+nol*a+b, ans1+nol*a+b*nol, ans2+ed*a+b, ans2+ed*a+b*ed))
            
    
            
