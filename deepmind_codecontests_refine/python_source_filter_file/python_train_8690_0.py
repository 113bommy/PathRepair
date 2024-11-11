n = int(input())
for i in range(n):
    print(n-i if i%2 else i+1, end=' ')
