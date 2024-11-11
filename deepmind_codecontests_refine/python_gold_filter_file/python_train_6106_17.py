n = int(input())
arr = list(map(int,input().split()))
b = list(map(int,list(input())))
l  = int(-1e9)
r = int(1e9)
for i in range(4,n):
    if b[i] != b[i-1]:
        if b[i]:
            m = -1e10
            for g in range(i-4,i+1):
                m = max(arr[g],m)
            l = max(l,m+1)
        else:
            m = 1e10
            for g in range(i - 4, i+1):
                m = min(arr[g], m)

            r = min(r, m - 1)
print(l,r)