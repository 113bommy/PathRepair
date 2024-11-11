N=int(input())

arr = [0]+list(map(int,input().split()))

max_index = 0
max_ = 0
for i in range(N+1):
    if abs(arr[i]) > max_:
        max_ = abs(arr[i])
        max_index = i

print(2*N-2)
for i in range(1,N+1):
    if i != max_index:
        print('{0} {1}'.format(max_index, i))

if arr[max_index] > 0:
    for i in range(1,N):
        print('{0} {1}'.format(i, i+1))
else:
    for i in range(N, 1,-1):
        print('{0} {1}'.format(i, i-1))