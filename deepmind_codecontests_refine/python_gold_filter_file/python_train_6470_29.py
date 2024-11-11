l = int(input())
s = input()


def func(s, l):
    turns = (l - 11)
    eights = sum(1 if c == '8' else 0 for c in s[:turns+1])
    return eights > turns // 2


res = func(s, l)
if res:
    print("YES")
else:
    print("NO")
