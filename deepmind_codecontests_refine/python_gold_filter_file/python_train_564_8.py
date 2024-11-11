'''
# https://www.jdoodle.com/python3-programming-online/
#
# 22.07.2021
#
# CF 258 B
#
'''

def CheckArray (s, t) :
    lens = len (s); lent = len (t)
    if lens != lent :
        return 0
    sa = [0]*26
    ta = [0]*26
    for i in range (lens) :
        sa [ord (s [i]) - ord ('a')] += 1
        ta [ord (t [i]) - ord ('a')] += 1
    for i in range (26) :
        if sa [i] != ta [i] :
            return 0
    return 1

def CheckAutomataArray (s, t) :
    lens = len (s); lent = len (t)
    if lens < lent :
        return 0
    sa = [0]*26
    ta = [0]*26
    for i in range (lens) :
        sa [ord (s [i]) - ord ('a')] += 1
    for i in range (lent) :
        ta [ord (t [i]) - ord ('a')] += 1
    for i in range (26) :
        if sa [i] < ta [i] :
            return 0
    return 1

def CheckAutomata (s, t) :
    lens = len (s); lent = len (t)
    if lens < lent :
        return 0
    i = 0; j = 0
    while i < lens and j < lent :
        if s [i] != t [j] :
            i += 1
        else :
            i += 1; j += 1
    if j < lent :
        return 0
    return 1

s = input ()
t = input ()

if CheckAutomata (s, t) == 1 :
    print ("automaton")
elif CheckArray (s, t) == 1 :
    print ("array")
elif CheckAutomataArray (s, t) == 1 :
    print ("both")
else :
    print ('need tree')
