def broken(s):
    for i in range(len(s)):
        if s[i] == "B":
            b = i % 4
        elif s[i] == "Y":
            y = i % 4
        elif s[i] == "R":
            r = i % 4
        elif s[i] == "G":
            g = i % 4
    count1, count2, count3, count4 = 0, 0, 0, 0
    for i in range(len(s)):
        if s[i] == "!":
            if i % 4 == b:
                count1 += 1
            elif i % 4 == y:
                count2 += 1
            elif i % 4 == r:
                count3 += 1
            elif i % 4 == g:
                count4 += 1
    return count1, count2, count3, count4


print(*broken(input()))
