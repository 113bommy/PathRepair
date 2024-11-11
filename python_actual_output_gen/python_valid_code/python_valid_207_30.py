n = int(input())
if n == 1:
    print(-1)
    exit()
for i in range(n):
    if i&1:
        print(i-1, end=" ")
    else:
        print(i+1, end=" ")