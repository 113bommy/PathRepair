N, L = map(int, input().split())

A = list(map(int, input().split()))

ans_index = -1
for i in range(N-1):
    if A[i] + A[i+1] >= L:
        ans_index = i
        break

if ans_index == -1:
    print('Impossible')
    exit()
print('Possible')

ans_index += 1
for i in range(1, ans_index):
    print(i)
for i in range(N-1, ans_index, -1):
    print(i)

print(ans_index)
