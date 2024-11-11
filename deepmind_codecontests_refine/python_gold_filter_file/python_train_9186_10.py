n = int(input())
a = list(map(int,input().split()))
max = 0
for i in range(n):
    for j in range(i, n):
        for k in range(j, n):
            if max < a[i] | a[j] | a[k]:
                max = a[i] | a[j] | a[k]
print(max)