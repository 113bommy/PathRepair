t = int(input())
for x in range(t):
    n = int(input())
    p = [n + 10] + list(map(int, input().split()))
    p.append(n + 10)
    i = 0
    ind1 = 0
    while i < n:
        if p[i] == 1:
            ind1 = i
            i = n
        i += 1
    ind2 = ind1
    d = 1
    maks = 1
    answer = ""
    while d < n:
        if maks <= d:
            answer += "1"
        else:
            answer += "0"
        a = p[ind1 - 1]
        b = p[ind2 + 1]
        if a < b:
            ind1 -= 1
            if maks < a:
                maks = a
        else:
            ind2 += 1
            if maks < b:
                maks = b
        d += 1
    answer += "1"
    print(answer)