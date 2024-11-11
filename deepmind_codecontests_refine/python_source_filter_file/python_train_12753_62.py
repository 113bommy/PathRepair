import sys
import math

#to read string
get_string = lambda: sys.stdin.readline().strip()
#to read list of integers
get_int_list = lambda: list( map(int,sys.stdin.readline().strip().split()) )
#to read non spaced string and elements are integers to list of int
get_intList_from_str = lambda: list(map(int,list(sys.stdin.readline().strip())))
#to read non spaced string and elements are character to list of character
get_charList_from_str = lambda: list(sys.stdin.readline().strip())
#get word sepetared list of character
get_char_list = lambda: sys.stdin.readline().strip().split() 
#to read integers
get_int = lambda: int(sys.stdin.readline())
#to print faster
pt = lambda x: sys.stdout.write(str(x))

#--------------------------------WhiteHat010--------------------------------#
dist = get_int()
p = get_int()
q = get_int()
print( p/(p+q)*dist,2 )