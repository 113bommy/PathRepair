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
l1 = get_int_list()
l2  = get_int_list()

count = 0
for i in range(3):
    if l1[i] == l2[i]:
        count += 1
if count == 2:
    print("YES")
else:
    print("NO")
