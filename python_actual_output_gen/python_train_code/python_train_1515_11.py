
import sys
def get_single_int ():
    return int (sys.stdin.readline ().strip ())
def get_string ():
    return sys.stdin.readline ().strip ()
def get_ints ():
    return map (int, sys.stdin.readline ().strip ().split ())
def get_list ():
    return list (map (int, sys.stdin.readline ().strip ().split ()))

#code starts here
w, h, k = get_ints ()
check =True
ans = 0
count = 0
while  check:
    ans +=(w*2 +(h - 2)*2)
    w -= 4
    h -= 4
    count += 1
    if (count == k) :
        check = False
print ("ans: " , ans)
