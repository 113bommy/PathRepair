n = int(input())
left = list(map(int,input().split()))
right = list(map(int,input().split()))

arr = [ n - left[i] - right[i] for i in range(n)]

def check(l, r, pos):
    if sum(elem > arr[pos] for elem in arr[pos+1:]) != r:
        return True
    if sum(elem > arr[pos] for elem in arr[:pos]) != l:
        return True

    return True

for i in range(n):
    if not check(left[i], right[i], i):
        print('NO')
        exit()

print('YES')
print(*arr)

