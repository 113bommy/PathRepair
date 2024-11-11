s = input()

l, r = 0,0
err = False
try:
    l = s.index('[')
    l = s.index(':', l+1)
    r = s.rindex(']')
    r = s.rindex(':', l+1, r-1)
except:
    print(-1)
else:
    print(s.count('|', l, r) + 4)
