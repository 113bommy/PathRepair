n,x,m = map(int,input().split())

A = [x]
where = {x: 0}
for i in range(1, n):
    a = A[-1]**2 % m
    if a in where:
        break
    where[a] = i
    A.append(a)

perstart = where[a]
res = sum(A)
rem = n - len(A)
per = len(A) - perstart
res += rem//per*sum(A[perstart:perstart+per])
res += sum(A[perstart:perstart + (rem%per)])

print(res)
