from collections import deque
n, l = map(int, input().split())
a = list(map(int, input().split()))
last = -1
for i in range(1,n):
    if a[i-1] + a[i] >= l :
        last = i
if last == -1:
    print("Impossible")
else:
    print("Possible")
    for i in range(1, last):
        print(i)
    for i in range(last+1, n):
        print(i)
    print(last)