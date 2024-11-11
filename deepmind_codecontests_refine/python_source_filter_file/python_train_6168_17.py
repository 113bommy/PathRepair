from collections import Counter
def rn():
    a = int(input())
    return a
def rl():
    a = list(map(int, input().split()))
    return a
for _ in range(int(input())):
    #n = int(input())
    [n,k] = rl()
    s = input()
    sl = [i for i in s]
    sl.sort()
    mc = 1
    ch = sl[0]
    for i in range(1,n):
        if sl[i]==ch:
            mc += 1
    if mc<k:
        print(sl[k-1])
        continue
    c =  len(Counter(sl).keys())
    ans = ch
    if c == 1:
        for i in range((mc+k-1)//k-1):
            ans = ch+ans
    elif c == 2 and mc==k:
        for i in range((n-mc+k-1)//k):
            ans = ans+sl[mc]
    else:
        for i in range(mc,n):
            ans = ans+sl[i]
    print(ans)

