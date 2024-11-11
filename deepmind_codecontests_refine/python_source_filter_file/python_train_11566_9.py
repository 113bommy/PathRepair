import sys
import io

stream_enable = 0

inpstream = """
7
1 2 3 1 2 3 4

"""

if stream_enable:
    sys.stdin = io.StringIO(inpstream)
    input()

def inpmap():
    return list(map(int, input().split()))

n = int(input())
arr = inpmap()
r = []
for i in range(n - 1):
    if arr[i] > arr[i + 1]:
        r.append(arr[i])
r.append(arr[n - 1])
print(len(r))
print(*r)
