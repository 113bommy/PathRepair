n = int(input())
b = input().split()
k = int(input())
for i in range(k):
    x, y = map(int, input().split())
    x -= 1
    if (x != 0):
        b[x-1] = int(b[x-1]) + (y-1)  
    if (x != n-1):
        b[x+1] = int(b[x+1]) + (int(b[x]) - y)
    b[x] = 0
    
for i in range(n):
    print(b[i])
        