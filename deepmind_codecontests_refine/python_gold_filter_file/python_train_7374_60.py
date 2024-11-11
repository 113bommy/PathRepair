n = int(input())
c=0
for i in range(n):
    s,e = map(int,input().split())
    c += e-s+1
print(c)