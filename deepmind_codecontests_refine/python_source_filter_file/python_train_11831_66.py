def isVowel(c):
    return c == 'a' or c=='e' or c=='i' or c=='o' or c=='u'
def isDigit(n):
    return n=='0' or n=='2' or n=='4' or n=='6' or n=='8'
c = 0
s = input()
for i in range(len(s)):
    if isVowel(s[i]) or isDigit(s[i]):
        c += 1
print(c)