import sys
input = sys.stdin.readline
def multi_input():
    return map(int, input().split())

def array_print(arr):
    print(' '.join(map(str, arr)))


n = int(input())
a = list(multi_input())
b = sorted(a)

for i in range(1,n):
    a[i] = a[i] + a[i-1]
    b[i] = b[i] + b[i-1]

for q in range(int(input())):
    t, l, r = multi_input()
    if t==1:
        if l>1:
            print(a[r-1] - a[l-2])
        else:
            print(a[r-1])
    else:
        if l>1: print(b[r-1]-b[l-2])
        else: print(a[r-1])