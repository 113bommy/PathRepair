a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
g, h, i = map(int, input().split())

if a-d==b-e==c-f and a-g==b-h==c-i and a-b--d-e==g-h and a-c==d-f==g-i:
    print("Yes")
else:
    print("No")