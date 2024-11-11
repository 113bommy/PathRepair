def dist(A, B):
    res = 0
    for i in range(len(A)):
        if(A[i] != B[i]):
            res += 1
    return res

def generate_new(number):
    global n, k
    R = [0] * n
    for i in range(n):
        R[i] = number 
        number += k
    return R

n, k = list(map(int, input().split()))
A = list(map(int, input().split()))
N = 1009
res = [0] * n
res_dist = N
for i in range(1, N):
    B = generate_new(i)
    cur_dist = dist(A, B)
    if(cur_dist < res_dist):
        res = B
        res_dist = cur_dist
print(res_dist)
for i in range(len(A)):
    if(A[i] < res[i]):
        print('+', i + 1, res[i] - A[i])
    elif(A[i] > res[i]):
        print('-', i + 1, A[i] - res[i])