'''input
6 6
'''
from math import log
n, m = map(int, input().split())
f = n*(log(m))
s = m*(log(n))
if(f==s):
    print('=')
elif(f>s):
    print('>')
else:
    print('<')