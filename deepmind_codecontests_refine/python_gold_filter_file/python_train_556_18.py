a,b=[1]*3,0
for _ in range(3):
    a[_]=list(map(int,input().split()))
    b+=sum(a[_])
for _ in range(3):
    a[_][_]=(b//2)-sum(a[_])
    print(*a[_])

# CodeBy: RAHUL MAHAJAN
# A2OJ: rahulmahajan
# CC: anonymous0201
# CF: rahulmahajan
# CSES: rahulmahajan