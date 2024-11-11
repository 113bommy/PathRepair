import bisect

N = int(input())
A = [-int(input()) for _ in range(N)]

p = [A[0]]
for i in A[1:]:
    if p[-1] <= i:
        p.append(i)
    else:
        p[bisect.bisect_right(p,i)] = i
print (len(p))