n = int(input())
q = list(map(int, input().split()))

shift = 0
l = 1

for i in range(n-1):
    if l+q[i]<=0:
        shift-=l+q[i]-1
        l = 1
    elif l+q[i]>n:
        shift-=l+q[i]-n
        l = n
    else:
        l+=q[i]
        

p = [1+shift]
for i in q: p.append(p[-1]+i)

if sorted(p)==[i+1 for i in range(n)]:
    print(*p)
else:
    print(-1)