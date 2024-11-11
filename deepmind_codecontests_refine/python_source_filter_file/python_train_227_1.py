T = int(input())

def solve():
    N = int(input())
    A = list(map(int,input().split()))

    if N == 1:
        return "YES"

    left_shear = []
    for i, a in enumerate(A):
        if a >=i and (i ==0 or left_shear[-1] != -1 ):
            left_shear.append(i)
        else:
            left_shear.append(-1)

    right_shear = []
    for i,a in enumerate(A):
        if a >=i and (i == 0 or right_shear[-1] != -1):
            right_shear.append(i)
        else:
            right_shear.append(-1)
    right_shear = right_shear[::-1]

    for i,a in enumerate(A):
        if i == 0:
            if right_shear[i+1] == -1:
                continue
            if a > right_shear[i+1]:
                return "YES"
        if i == len(A)-1:
            if left_shear[i-1] == -1:
                continue
            if a > left_shear[i-1]:
                return "YES"
        if left_shear[i] != -1 and right_shear[i] != -1:
            return "YES"
    return "NO"

for _ in range(T):
    print(solve())
