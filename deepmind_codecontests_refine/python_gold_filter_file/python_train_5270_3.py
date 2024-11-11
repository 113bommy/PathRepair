s = input()

def ans(s):
    vowel = {'a', 'e', 'i', 'o', 'u'}
    cc = 0
    begin = 0
    for i in range(len(s)):
        if s[i] in vowel:
            cc = 0
        else:
            cc +=1
        if cc>=3 and (s[i] != s[i-1] or s[i] != s[i-2] or s[i-1] != s[i-2]):
            print(s[begin:i], end = " ")
            cc = 1 
            begin = i
    print(s[begin:])

ans(s)