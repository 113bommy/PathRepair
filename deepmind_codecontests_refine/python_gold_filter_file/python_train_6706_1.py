n = int(input())
m = [int(i) for i in input().split()]
k = [0] * n
p = int(input())
l = list(range(1,n + 1))
j = []
for i in range(p):
    t = [int(i) for i in input().split()]

    if t[0] == 1:
        h = []
        a ,b= t[1] - 1,t[2]
        while b > 0 and a < n:
            if b <=m[a] - k[a]:
                k[a] += b
                break
            else:
                b = b -(m[a] - k[a])
                k[a] = m[a]
                h.append(a)
                a=l[a]
        for i in h:
            l[i] = a
    else:
        j.append(k[t[1] - 1])

print(*j,sep='\n')