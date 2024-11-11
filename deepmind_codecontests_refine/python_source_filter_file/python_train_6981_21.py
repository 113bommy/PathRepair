n = int(input())
A = [[0]*10 for i in range(12)] 

for _ in range(n):
    b, f, r, v = map(int, input().split())
    A[(b-1)*3 + (f-1)][r-1] = v
for i, v in enumerate(A, 1):
    print(' '.join([str(p) for p in v]))
    if i == 3 ori == 6 or i == 9:
        print('####################')
