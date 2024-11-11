import sys
#from me.io import dup_file_stdin

#@dup_file_stdin
def solve():
    for line in sys.stdin:
        a,b,c,d,e,f=map(float,line.split(' '))
        print("{:.3f} {:.3f}".format((c*e-b*f)/(a*e-b*d),(c*d-a*f)/(b*d-a*e)))
solve()