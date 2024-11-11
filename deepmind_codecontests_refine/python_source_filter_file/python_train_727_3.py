#coding:utf-8
n = int(input())
A = list(map(int, input().split()))
B = A[:]
B.sort()
C = [True for i in range(n)]
minA = min(A)

j = 0
a = []
total = 0
for i in range(n):
    circle = []
    j = i
    while C[j]:
        C[j] = False
        j = B.index(A[j])
        circle.append(A[j])
    n_c = len(circle)
    if n_c == 2:
        total += (circle[0]+circle[1])
    if n_c > 2:
        minc = min(circle)
        cirSum = sum(circle)
        total += min( cirSum + (n-2) * minc , cirSum + minc + (n+1)*minA)
    a.append(circle)
    

print(total)
