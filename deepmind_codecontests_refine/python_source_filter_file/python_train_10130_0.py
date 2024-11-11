import math
from collections import defaultdict
 
DEBUG = True
 
def log(*args, **kwargs):
    if DEBUG:
        print(*args, **kwargs)
 
def rint():
    return int(input())
 
def rlist(f=int):
    return list(map(f, input().split()))
 
def rstr():
    return input()
 
class Solution:
 
    def __init__(self):
        pass
        
    def run(self):

        n = rint()
        a = rlist()

        rem = [0] * 3
        total = 0
        equal = n // 3
        
        for x in a:
            rem[x % 3] += 1
            total += x

        result = 0
        for i in range(6):
            log(rem)
            if rem[i % 3] > equal:
                diff = rem[i % 3] - equal
                result += diff
                rem[(i + 1) % 3] += diff
                rem[i % 3] = equal

        return result


        # 0 --> 1, 1 --> 2, 2 --> 0
        
            
        
        
        
if __name__ == '__main__':
    
    t = int(input())
    s = Solution()
    #print(s.run())
    for i in range(t):
    #    s.run()
        print(s.run())
 
