n,m = map(int, input().split())
s = list(map(int, input().split()))
counter = 0
step = 0 
for i in range(1, n):
    if s[i] + s[i-1] < 5:
        step = 5 - s[i] - s[i-1]
        counter += step
        s[i] += step
        
print(counter)
print(*s)
