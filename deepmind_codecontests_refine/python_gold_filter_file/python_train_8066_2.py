i1 = 0
k = 0
#flag = False
#flagPLUS = False
#flagMINUS = False
n = int(input())

A =[]
for i in range(n):
    A.append(list(map(int, input().split())))
A.sort()
#n = len(a)
#print(A)
if n == 1:
    summ = A[0][1]
elif n == 2:
    summ = A[0][1]+A[1][1]
#k = -100001
elif A[n-1][0] < 0:
    summ = A[n-1][1]
elif A[0][0] > 0:
    summ = A[0][1]
else:
    summ = 0
    i = 0
    while A[i][0] < 0:
        i += 1
    k = i

    for i in range(min(k, len(A)-k)):
        summ += A[k+i][1]
        summ += A[k-1-i][1]
        i1 += 1
    if k > len(A)-k:
        summ += A[k-1-i1][1]
    elif k < len(A)-k:
        summ += A[k + i1][1]
print(summ)