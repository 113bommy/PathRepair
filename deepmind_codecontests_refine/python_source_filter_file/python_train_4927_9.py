T = int(input())
for _ in range(T):
    n = int(input())
    an = [int(e) for e in input().split()]
    # print(n, an)
    an = [(an[i],i+1) for i in range(len(an))]
    an.sort()

    ans = 0
    for i in range(0, len(an)):
        for j in range(i, len(an)):
            mul = an[i][0] * an[j][0]
            if mul > 2 * n:
                break 
            if mul == an[i][1] + an[j][1]: ans += 1
    print(ans)


