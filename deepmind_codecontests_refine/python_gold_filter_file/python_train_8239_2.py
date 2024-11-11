n = int(input())
l = list(map(int, input().split()))
t = l[0]
s = t
f = sum(l) // 2 + 1
k = []
p = 0
c = 0
if l[0]>=f:
    c = 1
    p = 1
    print(p)
    print(1)
else:
    for i in range(n):
        if t >= 2 * l[i]:
            k.append(i+1)
            s+=l[i]
            p+=1
        if s>=f:
            p+=1
            k.append(1)
            print(p)
            print(*k)
            c = 1
            break
if c == 0:
    print(0)