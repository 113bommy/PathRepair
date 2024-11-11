t = int(input())
for i in range(0, t):
    n = int(input())
    l = []
    freq = [0] * 26
    f = 0
    ls = []
    for j in range(0, n):
        s = input()
        ls.append(s)
    #print(*ls)
    for j in range(0, n):
        ss = ls[j]
        for k in range(0, len(ss)):
            ch = ss[k]
            freq[ord(ch) - 97] += 1
    for j in freq:
        if j % 2 != 0:
            f = 1
            break
    if f == 1:
        print("NO")
    else:
        print("YES")
