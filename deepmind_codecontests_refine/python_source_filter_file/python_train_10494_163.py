N, A, B, C, D = map(lambda x: int(x)-1, input().split())
L = input()
reachable = not "##" in L[A:C+1] or "##" in L[B:D+1]
interupt = "..." in L[B-1:D+2]
if reachable and (C < D or interupt):
    print("Yes")
else:
    print("No")
