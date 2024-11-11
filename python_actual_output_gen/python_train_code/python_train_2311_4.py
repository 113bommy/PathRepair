import sys

n = int(input())
s = list(input())
ans = list()

if len(s) < 2:
    print(len)
    print()
    sys.exit()

i = iter(s)
current = next(i)
prev = current
current = next(i)
iteratedTwice = False

#"good"
#"aabc"
try:
    while current is not None:
        if prev != current:
            ans.append(prev)
            ans.append(current)
        else:
            while prev == current:
                prev = current
                current = next(i)
            ans.append(prev)
            ans.append(current)
        current = next(i)
        iteratedTwice = False
        prev = current
        current = next(i)
        iteratedTwice = True
except StopIteration:
    print(len(s)-len(ans))
    print("".join(ans))
