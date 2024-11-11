import math

print(math.sin(math.radians(30)));
def solve():
    n = float(input());
    ans = 1.0
    
    for i in range(1, int(n / 2)):
        ans += 2*abs(math.sin(math.radians(90 / (n / 2) * (i))));
    print(ans)
    

t = int(input());
for _ in range(t):
    solve();