n = int(input())
a = list(map(int,input().split()))
a = [(a[i],i+1) for i in range(n)]

a.sort()

seen = [0] * (n+1)
ss = []
for i in range(1,n+1):
    if seen[i] == 0:
        s = [i]
        seen[i] = 1
        j = i
        while True:
            j = a[j-1][1]
            if seen[j] == 0:
                s.append(j)
                seen[j] = 1
            else:
                break
        ss.append(s)
print(len(ss))
for i in ss:
    print(len(i)," ".join(list(map(str,i))))
    