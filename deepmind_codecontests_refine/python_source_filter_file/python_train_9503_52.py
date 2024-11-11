import math
import string
import random
from random import randrange
from collections import deque
from collections import defaultdict

def solve(n):
    ans = 1
    
    n2 = 1
    for i in range(1, (n//2)+1):
        n2 *= i
    
    nf = 1
    for i in range(1, 21):
        nf *= i
    
    ans = nf//n2
    ans = ans//n2
    ans = ans//2
    
    ans = ans * (n2/(n//2))**2
    print(ans)
    
    return 

def main():
    n = int(input())
    # s = input().strip()
    # x,y = map(int, input().strip().split(" "))
    # arr = list(map(int, input().strip().split(" ")))
    
    solve(n)
        
    return

def test():
    arr_size = 25
    test_cases = 100
    min_range = -100
    max_range = 100
    str_size = 30
    step = 1
    
    for i in range(test_cases):
        k = []
        # s = ''.join(random.choices(string.ascii_lowercase, k = str_size))
        
        for j in range(arr_size):
            num = randrange(min_range, max_range, step)
            k.append(num)
        
        solve(n, arr)
        print("<-------- DEBUG ----------->")

    return 

if __name__ == '__main__':
    main()
    # test()
        
        