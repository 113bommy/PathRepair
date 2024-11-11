n, k = [int(x) for x in input().split()]
print((n-1)*6+5)
for i in range(n):
    print(k*(6*i+1),k*(6*i+3),k*(6*i+5),k*(6*i+2))