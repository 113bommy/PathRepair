import sys
import math

#to read string
get_string = lambda: sys.stdin.readline().strip()
#to read list of integers
get_int_list = lambda: list( map(int,sys.stdin.readline().strip().split()) )
#to read integers
get_int = lambda: int(sys.stdin.readline())
#to print fast
pt = lambda x: sys.stdout.write(str(x)+'\n')

#--------------------------------WhiteHat010--------------------------------------#
n = get_int()
s = set(get_int_list()[1:])
for i in range(n-1):
    s = s.intersection(set(get_int_list()[1:]))
lst = list(s)
print(*lst)
