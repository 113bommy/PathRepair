n = int(input())
ar = list(map(int, input().split()))
 
m = [0 for i in range(2*4*100000)]
for i in range(n):
    m[i - ar[i]] += ar[i]
print(m)
 
print(max(m))