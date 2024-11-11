import sys
input=sys.stdin.readline

N,A,B,C,D = map(int, input().split())
S = input().strip()

if "##" in S[A:C-1] or "##" in S[B:D-1]:
    print("No")
    exit()

if D < C:
#    print(S[A:D])
    if "..." not in S[B-1:D]:
        print("No")
        exit()
print("Yes")
