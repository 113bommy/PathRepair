N, L = map(int, input().split())
*A, = map(int, input().split())
for i, (a1, a2) in enumerate(zip(A, A[1:])):
    if a1 + a2 >= L:
        print('Possible')
        print(*([j+1 for j in range(i)]+[j+1 for j in range(N-2, i, -1)]+[i+1]), sep='\n')
        break
else:
    print('Impossible')