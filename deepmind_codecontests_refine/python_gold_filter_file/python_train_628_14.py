a,b,c = map(int,input().split())
t = 0
for i in range(a,b+1):
    if c % i == 0:
        t += 1
print(t)
