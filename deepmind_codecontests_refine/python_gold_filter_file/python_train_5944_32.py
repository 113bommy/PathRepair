n = int(input())
L = (list(map(int,input().split())))
for i in range(n):
    if L[i]%2==0:
        L[i] = L[i] - 1
print(*L)