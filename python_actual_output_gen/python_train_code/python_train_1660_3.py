def ravenstvo(s, t):
    count, prev = 0, 0
    for i in range(len(s)):
        if i + 1 < len(s) and s[i] == t[i]:
            prev = i + 1
        else:
            if i + 1 < len(s) and s[prev] != s[i] and s[prev] != t[prev]:
                prev = i + 1
                continue
            count += 1
            prev = i
    return count


n = int(input())
a = input()
b = input()
print(ravenstvo(a, b))
