d = []
n = int(input())
for i in range(n):
    a,b = map(int,input().split())
    d.append([a,-1])
    d.append([b,1])

d.sort()
t = 0
for i in d:
    t -= i[1]
    if t < -2:
        print("NO")
        break
print("YES")