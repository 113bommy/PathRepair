def inp():
    return map(int, input().split())
import sys;
import math;

n = int(input());
s = input();

if n == 1:
    print(s);
    sys.exit();

for i in range(1,n+1):
    if n%i == 0:
        s = s[i:0:-1] + s[i:]
print(s);
