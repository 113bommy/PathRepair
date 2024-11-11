def stones(s, t):
    j = 0
    for i in range(len(s)):
        if s[i] == t[j]:
            j += 1
    return j + 1


a = input()
b = input()
print(stones(a, b))
