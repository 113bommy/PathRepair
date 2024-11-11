n = int(input())
L = list(map(int, input().split()))
L.sort()
i = n-1
while i >= 0 and L[i] == L[n-1]:
    i -= 1
b = n-i-1
i = 0
while i < n and L[i] == L[0]:
    i += 1
a = i
if L[0] == L[n-1]:
    print(0,n*(n-1)//2)
else:
    print(L[n-1]-L[0],a*b)
