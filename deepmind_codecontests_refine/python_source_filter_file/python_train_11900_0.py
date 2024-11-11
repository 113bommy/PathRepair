
import math
from collections import defaultdict

n = input()

opt = defaultdict(lambda: 1e9)

def calc(s, cost):

    if cost >= opt[s]:
        return 1e9
    opt[s] = cost

    if cost + min(int(s[0]),5)*len(s) > opt['0']:
        return 1e9

    if s=='0':
        return cost
    
    if s[0]<'3':
        return calc( str(abs(int(s) - int('1'*len(s)))), cost + len(s))
    
    if s[0]>'7':
        return calc( str(int('1'*(len(s)+1)) - int(s)), cost + len(s)+1)


    a = calc( str(abs(int(s) - int('1'*len(s)))), cost + len(s))
    b = calc( str(int('1'*(len(s)+1)) - int(s)), cost + len(s)+1)

    return min(a,b)

calc(n,0)

print(opt['0'])

