for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    if A == sorted(A):
        print("YES")
        continue
    B = sorted(A, reverse=True)
    for a, b in zip(A, B):
        if a != b:
            print("YES")
            break
    else:
        if len(set(B)) == 1:
            print("YES")
        else:
            print("NO")