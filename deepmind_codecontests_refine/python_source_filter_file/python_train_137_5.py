import sys
from collections import Counter

readLine = lambda : sys.stdin.readline().rstrip()
readInt = lambda : int(sys.stdin.readline())
readInts = lambda : [int(x) for x in sys.stdin.readline().split(" ")]

def main():
    k = readInt()
    s = readLine()
    n = len(s)
    count = Counter(s)
    # There are (n / k) groups, so if all counts are divisible by (n / k)
    # and the sum of those dividends is k we can construct
    mult = {}
    for key, v in count.items():
        if v % k != 0:
            return -1
        mult[key] = v // k
    out = []
    for key, v in mult.items():
        out.append(key * v)
    return "".join(out) * (n // k)

print(main())