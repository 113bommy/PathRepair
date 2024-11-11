n = int(input())
for i in range(n):
    print(n-i//2 if i%2 else i//2+1, end=' ')
