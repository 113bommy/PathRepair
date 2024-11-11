from collections import defaultdict

def f(n):
    a,b,c = 0,0,0
    a = n//4
    r = n%4
    b = r//2
    c = r%2
    return (a,b,c)

h,w = map(int,input().split())
a = defaultdict(lambda:0)
for _ in range(h):
    for i in input():
        a[i] += 1
need = []
need.append((h//2)*(w//2))
need.append((h%2)*(w//2)+(w%2)*(h//2))
need.append((h%2)*(w%2))
data = [0]*3
for i in a.values():
    j,k,l = f(i)
    data[0] += j
    data[1] += k
    data[2] += l
if data[0] >= need[0]:
    data[1] += (data[0]-need[0])//2
    if data[1] == need[1] and data[2] == need[2]:
        print("Yes")
    else:
        print("No")
else:
    print("No")