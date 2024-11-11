# import os

n = int(input())

r = [i for i in range(1,700)]
s = ''.join(map(str, r))

print(s[n-1])
