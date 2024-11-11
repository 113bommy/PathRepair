n = int(input())
a,b = map(int,input().split())
l = []

[l.append(i) for i in range(b)]

for i in range(n-1):
    m,n = map(int,input().split())
    for j in range(m,n):
        if j in l:
            l.remove(j)
            
print(len(l))