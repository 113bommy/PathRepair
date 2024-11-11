from collections import deque
t = int(input())
rez = []

for i in range(t):
    A = input().split()
    a  = int(A[0])
    k = int(A[1])
    for j in range(k-1):
        max = 0
        min = 10
        for x in str(a):
            if int(x)> max:
                max = int(x)
            if int(x)<min:
                min = int(x)
            if min == 0:
                break
        if min == 0:
            break
        else:
            a += a + min*max
    rez.append(a)




for i in range(len(rez)):
    print(rez[i])