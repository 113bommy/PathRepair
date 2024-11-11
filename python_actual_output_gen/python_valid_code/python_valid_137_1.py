input()
s = list(input())
i = 0
while i < len(s):
    r = 0
    if s[i] == 'L':
        for i in range(s.index('L')+1):
            s.pop(0)
        i-=1
    elif s[i] == 'R':
        while s[i] != 'L' and i+1 < len(s):
            r+=1
            i+=1
        if s[i] == 'L':
            i -= r
            if len(s[i::i+r])%2 == 1:
                for x in range(r//2):
                    s.pop(i)
                i+=1
                for x in range(r//2):
                    s.pop(i)
                i-=1
            else:
                for x in range(r+1):
                    s.pop(i)
                i-=1
        else:
            i-=r
            for x in range(r+1):
                s.pop(i)
            i-=1
    i+=1
print(len(s))