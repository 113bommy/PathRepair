import sys
sys.setrecursionlimit(10000)
def recursion(left, right, painted_height):
    if left >= right:
        return 0
    mini = left + a[left:right].index(min(a[left:right]))
    allVerticles = right - left
    rec = a[mini] - painted_height + recursion(left, mini, a[mini]) + recursion(mini+1, right, a[mini])
    return min(allVerticles, rec)

n = int(input())
a = list(map(int, input().split()))

print(recursion(0, n, 0))