n = int(input())
a = list(map(int, input().split()))
t = 0
k = ''
for i in range(1,n):
    if a[i] == 1:
        t += 1
        k += str((a[i-1]))

print(t+1)
print(*k,a[-1])