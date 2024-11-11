def f(s):
    for i in range(len(s)):
        t = s[i:i + 26]
        if len(set(t)) == 26 or len(set(t)) + t.count('?') == 27:
            x = [ chr(ord('A') + j) for j in range(26) if chr(ord('A') + j) not in t]
            for j in range(26):
                if s[i + j] == '?':
                    s[i + j] = x.pop()
            for j in range(len(s)):
                if s[j] == '?':
                    s[j] = 'A'
            return ''.join(s)
    return -1
print(f(list(input())))