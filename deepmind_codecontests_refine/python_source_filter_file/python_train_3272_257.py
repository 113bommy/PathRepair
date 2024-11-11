n = int(input())
cols = list(map(int,input().split()))
while n>0:
    n-=1
    for i in reversed(range(n)):
        if cols[i] > cols[n]:
            cols[i],cols[n] = (cols[n], cols[i])
print(cols)