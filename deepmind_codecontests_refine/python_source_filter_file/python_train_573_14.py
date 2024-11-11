def strelba(a, b, c):
    flag = 0
    for i in range(0, c):
        z = c - a * i
        if z < 0:
            break
        if z % b == 0:
            flag = 1
            break
    if flag:
        return "YES"
    return "NO"


A, B, C = [int(k) for k in input().split()]
print(strelba(A, B, C))
