import sys
import math

#to read string
get_string = lambda: sys.stdin.readline().strip()
#to read list of integers
get_list = lambda: list( map(int,sys.stdin.readline().strip().split()) )
#to read non spaced string and elements are integers to list of int
get_intList_from_str = lambda: list(map(int,list(sys.stdin.readline().strip())))
#to read non spaced string and elements are character to list of character
get_charList_from_str = lambda: list(sys.stdin.readline().strip())
#to read integers
get_int = lambda: int(sys.stdin.readline().strip())
#to print faster
pt = lambda x: sys.stdout.write(str(x))

#--------------------------------WhiteHat010--------------------------------------#
n = get_int()
name = ''
fiboDP = [-1]*max(n,2)
fiboDP[0] = fiboDP[1] = 1
def fib(n):
    if fiboDP[n-1] != -1:
        return fiboDP[n-1]
    else:
        fiboDP[n-1] = fib(n-1) + fib(n-2)
for i in range(n):
    fib(i+1)

for i in range(1,n+1):
    if i in fiboDP:
        name += 'O'
    else: 
        name += 'o'

print(name) 
