p1 = tuple(map(int, input().split()))
p2 = tuple(map(int, input().split()))
p3 = tuple(map(int, input().split()))
p4 = tuple(map(int, input().split()))
if((p1[3] and (p1[0] or p1[1] or p1[2] or p4[2] or p2[0] or p3[1]))
        or (p2[3] and (p2[0] or p2[1] or p2[2] or p3[0] or p4[1] or p1[2]))
        or (p3[3] and (p3[0] or p3[1] or p3[2] or p4[0] or p1[1] or p2[2]))
        or (p4[3] and (p4[0] or p4[1] or p4[2] or p1[0] or p2[1] or p3[2]))):
    print("YES")
else:
    print("NO")
