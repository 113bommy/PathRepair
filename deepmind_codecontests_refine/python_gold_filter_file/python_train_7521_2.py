for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    fl = 0
    if a[0]==0: prev = "a"
    else: prev = "a"*a[0]
    ans = [prev]
    cur = prev[:a[0]]
    for i in range(1,n):
        cur = prev[:a[i-1]]
        if a[i]>a[i-1]:
            if cur:
                for j in range(ord("a"),ord("a")+26):
                    c = chr(j)
                    if c!=cur[-1]:
                        if len(prev)>len(cur):
                            if c!=prev[len(cur)]:
                                cur += c*(a[i]-a[i-1])
                                break
                        else:
                            cur += c*(a[i]-a[i-1])
                            break
            else:
                for j in range(ord("a"),ord("a")+26):
                    c = chr(j)
                    if c!=prev[0]:
                        cur += c*(a[i]-a[i-1])
                        break
        if len(cur)==0: 
            for j in range(ord("a"),ord("a")+26):
                c = chr(j)
                if c!=prev[0]:
                    cur += c
                    break
        ans.append(cur)
        prev = cur 
    if a[-1]==0:
        for j in range(ord("a"),ord("a")+26):
                c = chr(j)
                if c!=prev[0]:
                    ans.append(c)
                    break
    else: ans.append(cur[:a[-1]])
    for i in ans:
        print(i)    

            






