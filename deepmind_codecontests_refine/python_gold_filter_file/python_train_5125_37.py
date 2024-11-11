t = int(input())
for _ in range(t):
    n, d = map(int,input().split())
    sum = 0
    haybales = list(map(int,input().split())) 
    for i in range(n):
        res = haybales[i]
        if res * i <= d:
            sum += res
            d -= res*i
        else:
            res2 = d // i
            sum += res2
            break
    print(sum)