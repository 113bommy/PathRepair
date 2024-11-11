n, k = map(int, input().split(" "))

i = 2
table = []
while i * i <= n:
    while n % i == 0:
        n /= i
        table.append(i)

    i += 1
    
if n > 1:
    table.append(n)
    
if len(table) >= k:
    ans = []
    for j in range(k-1):
        ans.append(table[j])

    tmp = 1
    for j in range(k-1, len(table)):
        tmp *= table[j]

    ans.append(tmp)
    print(" ".join(map(str,ans)))
else:
    print(-1)