nm = input().split(" ")
n = int(nm[0])
m = int(nm[1])
c = 0
for a in range(max(n, m)+1):
    for b in range(max(n, m)+1) :
        if(a*a + b == n and a + b*b == m) :
            c += 1
print(c)

