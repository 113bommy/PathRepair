from sys import stdin, stdout 
from bisect import bisect_left, bisect_right
from collections import defaultdict
import math
cin = stdin.readline
def cout(x):
	stdout.write(str(x)+'\n')

def nexint():
    return int(stdin.readline())
def readline():
    return map(int,stdin.readline().split())
def readlist():
    return list(map(float,stdin.readline().split()))

def sorted_indexes(arr):
    return sorted(range(len(arr)),key=arr.__getitem__)
def printr(arr):
    [stdout.write(str(x)+' ')   for x in arr]
    cout('')

def find_lt(a, x):#'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):#'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError


# ---------------------Template ends-------------sdpt,sdpt131[Sudipta Banik]---------------------

def dist(x,y):
    return math.sqrt(x*x + y*y)








threshold = 1.5*(10**6)

n = nexint()
arr = []
for i in range(n):
    x = readlist()
    x.append(i)
    arr.append(x)
    # printr(arr[i])






ox,oy = 0,0

choices = [0]*n

dis = [max(abs(arr[i][0]),abs(arr[i][1])) for i in range(n)]

arr = [ar for _,ar in sorted(zip(dis,arr))]

for i in range(n-1,-1,-1):
    # print(i)
    c = 0

    ox1,oy1 = ox+arr[i][0],oy+arr[i][1]
    ox2,oy2 = ox-arr[i][0],oy-arr[i][1]

    d1 = dist(ox1,oy1)
    d2 = dist(ox2,oy2)

    if d1 <= d2:
        c = 1;
    else:
        c = -1

    choices[arr[i][2]] = c

    ox += c*arr[i][0]
    oy += c*arr[i][1]


if (dist(ox,oy) <= threshold):
    printr(choices)
else:
    for i in range(n):
        choices[i] = -1*choices[i]
    printr(choices)






