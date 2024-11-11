input()
x = sum(list(map(int, input().split())))
n = int(input())
for i in range(n):
    l, r = map(int, input().split())
    if l <= x <= r:
        print(x)
        break
    elif x < l:
        print(l)
        break
else:
    print(-1)
    
    
    
