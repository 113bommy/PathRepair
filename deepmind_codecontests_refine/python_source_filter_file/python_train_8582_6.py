
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
def unique (n) :
    if n == 8:
        print ("vaporeon")
    else:
        print ("espeon")
def same (names):
    for j in names:
        if j [i] != s [i]:
            try:
                names_copy.remove (j)
            except:
                continue

n = get_single_int ()
s = get_string ()
names = [ "jolteon", "flareon",  "umbreon", "leafeon", "glaceon", "sylveon"]
names_copy = [ "jolteon", "flareon",  "umbreon", "leafeon", "glaceon", "sylveon"]
if (n == 6 or n == 8):
    unique (n)
else :
    for i in range (7):
        if s [i] == '.':
            continue
        else:
            same (names)
print (names_copy [0])
