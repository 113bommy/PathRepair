n = int(input())
s = input()
if 'R' in s and 'L' in s:
     x = s.count('R')
     t = s.index('R')
     print(t+1,t+x)
else:
    if 'R' in s and 'L' not in s:
        x = s.count('R')
        t = s.index('R')
        print(t+1,t+x+1)
    else:
        x = s.count('L')
        t = s.index('L')
        print(t+x,t)
