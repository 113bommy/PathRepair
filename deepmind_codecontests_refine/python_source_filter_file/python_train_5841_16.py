n = int(input())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())
c1, c2 = map(int, input().split())
if (b1 < a1) and (b2 < a2) and (c1 < a1) and (c2 < a2):
    print("YES")
elif (b1 > a1) and (b2 > a2) and (c1 > a1) and (c2 > a2):
    print("YES")
elif (b1 > a1) and (b2 < a2) and (c1 > a1) and (c2 < a2):
    print("YES")
elif (b1 > a1) and (b2 < a2) and (c1 > a1) and (c2 < a2):
    print("YES")
else:
    print("NO")
