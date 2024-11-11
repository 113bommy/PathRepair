n = int(input())
l = [0] + list(map(int, input().split())) + [0]
res = 0
for i in range(1, n - 1):
    if l[i] == 1:
        res += 1
    if l[i] == 0 and l[i - 1] == 1 and l[i + 1]:
        res += 1
        
print(res)
    
    