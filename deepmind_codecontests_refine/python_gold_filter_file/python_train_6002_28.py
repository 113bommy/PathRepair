n, k = map(int, input().split())
sum = ((1+n)*n)//2
if k >= sum:
    k %= sum
for i in range(n, -1, -1):
        l = ((i+1)*i)//2
        if l<=k:
            print(abs(k-l))
            break
