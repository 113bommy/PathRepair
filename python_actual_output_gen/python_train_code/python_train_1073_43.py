vowels = ['a', 'e', 'i', 'o', 'u', 'y']


def editor(s):
    i = 0
    while i < len(s) - 1:
        if s[i] in vowels and s[i + 1] in vowels:
            s = s[i + 1:] + s[i + 2:]
            i -= 1
        i += 1
    return s


n = int(input())
t = input()
print(editor(t))
