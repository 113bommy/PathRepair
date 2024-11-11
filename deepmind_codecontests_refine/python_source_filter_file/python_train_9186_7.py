# python3 q5.py < test.txt

n = int(input())
a = [int(j) for j in input().split()]
ans = 0
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            ans = max(ans, a[i] | a[j] | a[k])
        
print(ans)