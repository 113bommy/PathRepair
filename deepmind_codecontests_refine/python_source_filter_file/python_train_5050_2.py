# import atexit
# import io
# import sys
#
# _INPUT_LINES = sys.stdin.read().splitlines()
# input = iter(_INPUT_LINES).__next__
# _OUTPUT_BUFFER = io.StringIO()
# sys.stdout = _OUTPUT_BUFFER
#
#
# @atexit.register
# def write():
#     sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

string = input()

occs = [0] * 26
for c in string:
    occs[ord(c) - ord('a')] += 1

mid = ''
res = list()

for idx in range(len(occs)):
    if (occs[idx] & 1) == 1:
        rightmostOdd = idx
        for i in range(len(occs) - 1, idx - 1, -1):
            if (occs[i] & 1) == 1:
                rightmostOdd = i
                break
        if rightmostOdd != occs[idx]:
            occs[rightmostOdd] -= 1
            occs[idx] += 1

    if (occs[idx] & 1) == 1:
        mid = chr(ord('a') + idx)
    res.extend(chr(ord('a') + idx) * (occs[idx] // 2))

print(''.join(res) + mid + ''.join(reversed(res)))
