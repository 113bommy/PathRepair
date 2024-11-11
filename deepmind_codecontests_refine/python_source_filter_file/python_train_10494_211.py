N, A, B, C, D = map(int, input().split())
S = input()
if ("##" in S[A:C+1]) or ("##" in S[B:B+1]):
    print("No")
else:
    if C < D:
        print("Yes")
    else:
        if "..." in S[B-2:D+1]:
            print("Yes")
        else:
            print("No")