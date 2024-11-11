
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
n, m = get_ints ()
rem = (m % (n*(n + 1)//2))
for i in range (1, n + 1):
    if rem - i <= 0:
        print (rem)
        break
    rem -= i
    

