from sys import *


def solve(a, m):
    for i in range(1, m+1):
        b = set()
        for j in a:
            b.add(j ^ i)
        if len(a-b) == 0:
            return i
    return -1


test = 1
test = int(input())
for t in range(0, test):
    # brr = [list(map(int,input().split())) for i in range(rows)]              # 2D array row-wise input
    n = int(input())
    # n, x = list(map(int, input().split()))
    arr = [int(x) for x in input().split()]
    m = max(arr)
    arr = set(arr)
    ans = solve(arr, m)
    print(ans)


'''
rows, cols = (5, 5)
arr = [[0]*cols for j in range(rows)]                                         # 2D array initialization
b=input().split()                                                             # list created by spliting about spaces
brr = [[int(b[cols*i+j]) for j in range(cols)] for i in range(rows)]          # 2D array Linear Input
rows,cols=len(brr),len(brr[0])                                                # no of rows/cols for 2D array
arr.sort(key = lambda x : x[1])                                               # sort list of tuples by 2nd element, Default priority - 1st Element then 2nd Element
s=set()                                                                       # empty set
a=maxsize                                                                     # initializing infinity
b=-maxsize                                                                    # initializing -infinity
mapped=list(map(function,input))                                              # to apply function to list element-wise
try:                                                                          # Error handling
    #code 1
except:                                                                       # ex. to stop at EOF
    #code 2 , if error occurs
'''
