a = int(input())
b = list(map(int, input().split()))
max = 0
c = [0]
m = c[0]
if b[0] != 0:
    print(1)
    exit()
else:
    for i in range(1,len(b)):
        if b[i-1] > max:
            max = b[i-1]
        elif b[i] > max + 1:
            print(i+1)
            exit()
print(-1)
