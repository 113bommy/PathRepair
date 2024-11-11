def palindromeSupersequence(s):
    return s + s[::1]

s = input()
print(palindromeSupersequence(s))