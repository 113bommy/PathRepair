t = int(input())
for i in range(t):
    a, b, k = map(int, input().split())
    if k%2 == 0:
        print( (k//2)* (a-b))
    else:
        print(((k//2)* (a-b))+1)