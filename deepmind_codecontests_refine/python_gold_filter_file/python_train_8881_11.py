t = int(input())
for u in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if(sum(a) != sum(b)):
        print(-1)
    else:
        s = [[(a[i] - b[i]), i] for i in range(n)]
        s.sort()
        i = 0
        j = n - 1
        ans = []
        while(i < j):

            e = abs(s[i][0])
            r = abs(s[j][0])

            for _ in range( min(e, r) ):
                ans.append([s[j][1] + 1, s[i][1] + 1])
            if e > r:
                s[i][0] += r
                j -= 1
            elif e < r:
                s[j][0] -= e
                i += 1
            else:
                i += 1
                j -= 1
        print(len(ans))
        for i in ans:
            print(*i)
        
        