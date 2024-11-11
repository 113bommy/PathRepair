a = int(input())
for i in range(a):
    n, k, d = map(int, input().split())
    s = list(map(int, input().split()))
    ans = []
    sett = []
    maxx = 6666666666666666666666666666666666666
    for i in range(d):
        ans.append(s[0])
        s.pop(0)
    sett = set(ans)
    p = 0 
    if len(sett) == 1:
        print(1)
    else:
        if maxx > len(sett):
            maxx = len(sett)
        for i in range(len(s)):
            ans.append(s[i])
            ans.pop(0)
            sett = set(ans)
            if len(sett) == 1:
                print(1)
                p = 1
                break
            else:
                if maxx > len(sett):
                    maxx = len(sett)
        if p == 0:
            print(maxx)
