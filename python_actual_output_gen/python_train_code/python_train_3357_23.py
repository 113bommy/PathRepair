n, k = map(int, input().split())
a = list(map(int, input().split()))

i = 0
avg = round(sum(a)/n, 2)

while avg < k - 0.5:
    i += 1
    avg = round((sum(a) + i*k) / (n+i), 2)
   

print(i)

