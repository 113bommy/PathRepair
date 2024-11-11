n = int(input())
s = input()
if s.count('R') == 0:
    print(n-s[::-1].index('L')+1, s.index('L')+1)
elif s.count('L') == 0:
    start = s.index('R')+1
    end = n-s[::-1].index('R')+1
    print(start, end)
else:
    start = s.index('R')+1
    end = n-s[::-1].index('R')
    print(start, end)