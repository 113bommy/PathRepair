import math
import atexit
import io
import sys
 
# input = sys.stdin.readline
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER
 
@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
 
def array_to_string(a):
    s = ""
    for i in a:
        s += str(i)
    return s
 
n = int(input())
d = dict()
for i in range(4):
    s = input()
    for j in s:
        if j == '.':
            continue
        val = int(j)
        if d.get(val):
            d[val] += 1
            continue
        d[val] = 1
m = n*2
# print(m)
f = 0
# print(d)
for k,v in d.items():
    if v>m:
        print(k,v)
        f = 1
        break
if f == 0:
    print("YES")
else:
    print("NO")