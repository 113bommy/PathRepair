a, b, k = map(int,input().split())

for i in range(a, b+1):
    if  i <= a+k-1 or b+1-k <= i:
        print(i)