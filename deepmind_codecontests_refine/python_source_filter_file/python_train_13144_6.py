t = int(input())
while t:
    t-=1
    n = int(input())
    s = input()
    l = [int(i) for i in s]
    pre = 0
    d = dict()
    d[0] = 1
    for i in range(n):
        pre+= l[i]
        temp = pre-(i+1)
        if temp not in d:
            d[temp] = 1
        else:
            d[temp]+=1
    ans = 0
    for i in d:
        ans += (2**(d[i]-1) -1)
    print(ans)