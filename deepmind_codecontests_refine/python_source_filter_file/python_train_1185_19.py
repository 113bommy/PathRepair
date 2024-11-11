a,b,c,d = map(int, input().split())

p1 = a/b
p2 = c/d

r = (1-p2)*(1-p1)

c = 0
ans = p1
for i in range(1,100):
    ans += p1*r**i

print(ans)