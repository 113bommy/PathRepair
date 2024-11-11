n,a,b = map(int,input().split())
c = 0
for i in range(n+1):
    if a <= sum(int(j) for j in str(i)) <= b:
        c += i
print(c)