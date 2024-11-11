a, b, c = map(int, input().split())

if a*b < (c-a-b)**2/4 and c-a-b >= 0:
    print("Yes")
else:
    print("No")