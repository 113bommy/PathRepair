l = str(input())
m = int(l.split()[0])
s = int(l.split()[1])

if (s==0 and m>1) or (s>m*9):
    print(-1,-1)
    exit()

k = s
for i in range(m-1,-1,-1):
    j = max(0,k-9*i)
    if j==0 and i==m-1:
        j = 1
    print(j, end='')
    k -= j

print(' ', end='')

k = s        
for i in range(m-1,-1,-1):
    j = min(9,k)
    print(j, end='')
    k -= j
print()
