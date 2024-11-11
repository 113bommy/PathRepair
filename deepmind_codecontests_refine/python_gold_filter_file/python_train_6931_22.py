n = int(input())
a = [1]*(n+2)
for i in range(2, n+2):
    if a[i] == 1:
        j = 2*i
        while j < n+2:
            a[j] = 2
            j += i
print(2) if n > 2 else print(1)
print(*(a[2:]))
