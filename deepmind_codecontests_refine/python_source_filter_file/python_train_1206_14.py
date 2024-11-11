import sys
import math

#to read string
get_string = lambda: sys.stdin.readline().strip()
#to read list of integers
get_int_list = lambda: list( map(int,sys.stdin.readline().strip().split()) )
#to read integers
get_int = lambda: int(sys.stdin.readline())

#--------------------------------WhiteHat010--------------------------------------#
s = get_string()
match = 'heidi'
pointer = 0

flag = False
for i in s:
    if i == match[pointer]:
        pointer += 1
        if pointer == 4:
            flag = True
            break
if flag:
    print("YES")
else:
    print("NO")