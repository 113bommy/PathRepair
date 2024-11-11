a, b = map(int, input().split())
n=int(input())
t=float("inf")
for i in range(n):
    x, y, v =map(int, input().split())
    if x==a:
        t=min(t, abs(b-y)/v)
    elif y==b:
        t=min(t, abs(a-x)/v)
    else:
        t=min(t, (abs(b-y)**2+abs(a-x)**2)**0.5)
print(t)
