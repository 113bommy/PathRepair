def sol(s):
    l = list(s)
    alpha = "abcdefghijklmnopqrstuvwxyz"
    alpha = alpha.upper()
    i = 0
    j = 0
    n = len(s)
    dp = set()
    while j < n:
        if l[j] not in dp:
            dp.add(l[j])
        elif l[j] != "?":
            while l[i] != l[j]:
                if l[i] != "?":
                    dp.remove(l[i])
                i+=1
            i+=1
        j+=1
        if j-i == 26:
            break
    if j-i < 26:
        return -1
    for it in range(i,j):
        if l[it] == "?":
            for ch in alpha:
                if ch not in dp:
                    l[it] = ch
                    dp.add(ch)
                    break
    for ch in range(i):
        if l[ch] == "?":
            l[ch] = "A"

    for ch in range(j+1, n):
        if l[ch] == "?":
            l[ch] = "A"

    return "".join(l)


s = input()
print(sol(s))