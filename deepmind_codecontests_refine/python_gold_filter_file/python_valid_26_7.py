for _ in range(int(input())):
    s = input()
    s1 = []
    s2 = []
    n = len(s)
    for i in range(n):
        if i%2==0:
            if s[i] == '?':
                s1.append(1)
                s2.append(0)
            else:
                s1.append(int(s[i]))
                s2.append(int(s[i]))
        else:
            if s[i] == '?':
                s2.append(1)
                s1.append(0)
            else:
                s1.append(int(s[i]))
                s2.append(int(s[i]))
    ans1 = 0 
    t1,t2 = 0,0
    l1,l2 = 5,5 
    for i in range(n):
        if i%2==0:
            t1 = t1 + s1[i]
            l1 = l1 - 1 
        else:
            t2 = t2 + s1[i]
            l2 = l2 - 1 
        ans1 = ans1 + 1 
        if t1 > t2 + l2:
            break
    ans2 = 0 
    t1,t2 = 0,0
    l1,l2 = 5,5 
    for i in range(n):
        if i%2==0:
            t1 = t1 + s2[i]
            l1 = l1 - 1 
        else:
            t2 = t2 + s2[i]
            l2 = l2 - 1 
        ans2 = ans2 + 1 
        if t2 > t1 + l1:
            break
    print(min(ans1,ans2))