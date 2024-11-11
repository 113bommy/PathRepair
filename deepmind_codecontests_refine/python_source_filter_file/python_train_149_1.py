n, m = map(int,input().split())
w = [int(x) for x in input().split()]
b = [(int(x)-1) for x in input().split()]
w  += [0]
a = 0
for i in range(m):
    for j in range(i-1,-1,-1):
        if b[j] == b[i]:
            b[i] = n
            break
        a += w[b[j]]
print(a)