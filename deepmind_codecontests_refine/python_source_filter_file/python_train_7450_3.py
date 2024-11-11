n,k = [int(i) for i in input().split()]

res = 0
d = 2**n - 1
cur = n
while (1):
    if ((d+1)//2 == k):
        print(cur)
        break
    cur -= 1
    if (k > (d+1)//2):
        k = d - (d+1)//2
    d = 2**cur - 1

