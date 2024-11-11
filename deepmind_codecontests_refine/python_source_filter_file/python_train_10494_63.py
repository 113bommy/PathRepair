N, A, B, C, D = map(int, input().split())
S = "#"+input()+"#"

if "##" in S[A:max(C, D)]:
    print("No")
    exit()

if C > D:
    if "..." in S[B-2:D+1]:
        print("Yes")
    else:
        print("No")
else:
    print("Yes")