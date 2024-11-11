def partition(a, p, r):
    q  = p
    for i in range(p, r):
        if a[i][1] <= a[r][1]:
            a[q], a[i] = a[i], a[q]
            q += 1
    a[q], a[r] = a[r], a[q]
    return q 
 
def quicksort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quicksort(a, p, q-1)
        quicksort(a, q+1, r)
 
def check_stable(a):
    for i in range(1, len(a)):
        if a[i - 1][1] == a[i][1]:
            if a[i - 1][2] > a[i][2]:
                return 'Not stable'
    return 'Stable '
     
import sys
n = int(sys.stdin.readline())
a = []
for i in range(n):
    suit, num = sys.stdin.readline().split()
    a += [[suit, int(num), i]]
 
quicksort(a, 0, len(a) - 1)
print(check_stable(a))
 
for line in a:
    print(line[0],line[1])