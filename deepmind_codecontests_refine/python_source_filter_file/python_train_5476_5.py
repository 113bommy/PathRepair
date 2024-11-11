##n = int(input())
##a = list(map(int, input().split()))
##print(' '.join(map(str, res)))
def list_input():
    return list(map(int, input().split()))

[n, m] = list_input()
l = list_input()

a = [-1 for i in range(n)]
used = [0 for i in range(n+1)]
for i in range(m-1):
    id = l[i]-1
    dist = l[i+1]-l[i]
    if dist <= 0: 
        dist += n
    if (a[id] > -1 and a[id] != dist) or (a[id] == -1 and used[dist] == 1):
        print('-1')
        exit(0)
    a[id] = dist
    used[dist] = 1

k = 1
for i in range(n):
    if a[i] == -1:
        while k <= n and used[k] > -1:
            k += 1
        a[i] = k
        k += 1
print(' '.join(map(str, a)))