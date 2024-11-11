"""
Oh, Grantors of Dark Disgrace, 
Do Not Wake Me Again.
"""

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())
si = lambda: input()

for _ in range(ii()):

    n = ii()
    l = si()
    if (n < 11):
        print("NO")
    elif l.count('8') == 0:
        print("NO")
    elif l.count('8') > 0:
        if l.index('8') > 11:
            print("NO")
        else:
            s = l[l.index('8'):]
            if len(s) > 11:
                print("YES")
            else:
                print("NO")       
