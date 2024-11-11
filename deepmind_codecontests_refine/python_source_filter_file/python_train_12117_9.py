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
d = {}
for _ in range(n):
    a,b = get_int_list()
    d[a] = a+b

flag = False
for k,v in d.items():
    if v in d and d[v] + v == k:
        flag = True
        break
if flag:
    print("YES")
else:
    print("NO")