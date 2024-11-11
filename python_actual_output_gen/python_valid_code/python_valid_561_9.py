t = int(input())
for i10 in range(t):
    n = int(input())
    s = input()
    if not('b' in s and 'a' in s):
        print('-1 -1')
    else:
        for i in range(len(s)):
            if s[i] != s[i+1]:
                print(i, i+1)
                break