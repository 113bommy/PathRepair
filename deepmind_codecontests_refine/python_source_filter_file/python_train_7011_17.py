nm = input().split(" ")
n = int(nm[0])
m = int(nm[1])
c = 0
for a in range(max(n, m)):
    for b in range(max(n, m)) :
        if(a*a + b == n and a + b*b == m) :
            c += 1
print(c)

