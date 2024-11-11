n,m = list(map(int,input().split()))
a = list(map(int,input().split()))
j = 1
k = 0
for i in a:
    if i>=j:
        k+=(i-j)
        j = i
    else:
        k+=(n-j+1)
        j = 1
        k+=(i-j)
        j = i
print(k)
