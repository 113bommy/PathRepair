t = int(input())
for i in range(t):
    r,g,b,w = map(int,input().split())
    num = sum([r%2,g%2,b%2,w%2]) % 4
    if num <= 1:
        print("YES")
    elif num == 3 and min([r,g,b]) > 0:
        print("YES")
    else:
        print("NO")
