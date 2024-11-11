import sys

data = sys.stdin.readlines()[0].split()[0]

counters = [0, 0, 0]
ok = True

for idx, letter in enumerate(data):
    if idx > 1:
        if letter >= data[idx - 1]:
            counters[ord(letter) - ord('a')] += 1
        else:
            ok = False
            break
    else:
        counters[ord(letter) - ord('a')] += 1

if (counters[0] > 0 and counters[1] > 0 and
   (counters[2] == counters[0] or counters[2] == counters[1]) and
   ok is True):
    print("YES")
else:
    print("NO")
