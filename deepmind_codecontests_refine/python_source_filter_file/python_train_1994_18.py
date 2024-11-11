n = int(input())
a = list(map(int, input().split()))
s = set(a)
if n == 1 or len(s) == 1:
    print(0)
else:
    s = sorted(s)
    if len(s) == 2:
        av = sum(a) / n
        if av == int(av):
            print(s[1] - int(av))
        else:
            print(s[1] - s[0])
    elif len(s) == 3 and s[2] - s[1] == s[1] - s[0]:
        print(s[2] - s[1])
    else:
        print(-1)