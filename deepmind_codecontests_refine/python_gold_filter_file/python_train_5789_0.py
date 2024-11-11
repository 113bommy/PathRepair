import sys
A = []
for i in range(4):
    s = list(map(int, input().split()))
    A.append(s)
B = [A[i][3] for i in range(4)]
for i in range(4):
    for j in range(3):
        if A[i][j] == 1:
            if j == 0:
                if B[i] or B[(i - 1)%4]:
                    print("YES")
                    sys.exit()
            elif j == 2:
                if B[i] or B[(i + 1)%4]:
                    print("YES")
                    sys.exit()
            else:
                if i < 2:
                    if B[i] or B[i + 2]:
                        print("YES")
                        sys.exit()
                else:
                    if B[i] or B[i - 2]:
                        print("YES")
                        sys.exit()
print("NO")
