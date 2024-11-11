n = int(input())
a = list(map(int,input().split()))
amax = max(a)
amin = min(a)

print(2*n)
if amax > abs(amin):
    a_i = a.index(amax)
else:
    amax += amin
    a_i = a.index(amin)
for i in range(n):
    print(a_i+1,i+1)

if amax > 0:
    for i in range(n-1):
        print(i+1,i+2)
else:
    for i in range(n,1,-1):
        print(i,i-1)
