n= int(input())
for i in range(n):
    m = int(input())
    list_a = list(map(int, input().split()))
    output = 0
    for i in range(m-1):
        output = max(output, list_a[i]*list_a[i+1])
    print(output)