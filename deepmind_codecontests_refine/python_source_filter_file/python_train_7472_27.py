from itertools import chain

N = int(input())
zenhan = []
kouhan = []
for _ in range(N):
    si = input()
    last = 0
    low = last
    high = last
    for s in si:
        if s == "(":
            last += 1
        else:
            last -= 1
        low = min(low, last)
        high = max(high, last)
    if last >= 0:
        zenhan.append((-low, last, low))
    else:
        kouhan.append((last - low, last, low))
zenhan.sort()
kouhan.sort()

open_close = 0
for key, last, low in chain(zenhan, kouhan):
    if open_close + low < 0:
        ans = "No"
        break
    else:
        open_close += last
else:
    if open_close:
        ans = "No"
    else:
        ans = "Yes"
print(ans)