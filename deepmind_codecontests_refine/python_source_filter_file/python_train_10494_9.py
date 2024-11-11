N,A,B,C,D = map(int, input().split())
S = input()

if "##" in S[A-1:max(C-1,D-1)]:
    print("No")
elif D < C and ("..." not in S[B-2:D-1]):
    print("No")
else:
    print("Yes")