n = int(input())
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a
arr = list(map(int,input().split()))
g = arr[0]
for i in range(n):
    g = gcd(g, arr[i])
answer = 1
i = 2
while i * i <= g:
    if g % i == 0:
        cur = 0
        while g % i == 0:
            g //= i
            cur += 1
        answer *= cur + 1
    i += 1
if g > 1:
    answer *= 2
    
print(answer)