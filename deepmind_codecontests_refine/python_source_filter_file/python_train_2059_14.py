a, x = map(int,input().split())
b, y = map(int,input().split())
t = int(input())

if abs(x-y)*t >= abs(a-b):
    print("YES")
else:
    print("NO")
