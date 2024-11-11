N = int(input())
A = list(map(int, input().split()))

f = A.count(5)
z = A.count(0)

if  z < 1:
    print(-1)
else:
    S = "5" * (f - (f % 9)) + "0" * z
    print(int(S))