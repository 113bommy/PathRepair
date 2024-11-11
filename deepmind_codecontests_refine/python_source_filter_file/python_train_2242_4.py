n = int(input())
s = input()
a = list(map(int,input().split()))
k = 0
i = 0 
while k < n:
    if s[i]=='>':
        k += a[i]
        i += a[i]
    else:
        k += a[i]
        i -= a[i]
    if i < 0 or i >= n:
        exit(print("FINITE"))

print("INFINITE")