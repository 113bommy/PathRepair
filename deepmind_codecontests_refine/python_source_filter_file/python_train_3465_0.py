t = int(input())

for _ in range(t):
    a,b = map(int,input().split())
    s = input()

    if s.count("1") == 0:
        print(0)
        exit()
    
    n = len(s)
    aida = []
    k = 0
    for i in range(n):
        if s[i] == "1" and (i == 0 or s[i-1] == "0"):
            aida.append(k)
            k = 0
        elif s[i] == "0":
            k += 1

    ans = a
    for i in aida[1:]:
        if a < b*i:
            ans += a
        else:
            ans += b*i
    print(ans)