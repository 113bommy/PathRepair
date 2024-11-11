n = int(input())
m = []
for i in range(n):
    m.append(list(map(int,input().split())))

x = m[1][2]
y = m[0][2]/m[0][1]
a3 = int((x*y)**0.5)
a2 = x//a3
a1 = m[0][1]//a2
a = [a1,a2,a3]
for i in range(3,n):
    a.append(m[0][i]//a1)
print(a)

