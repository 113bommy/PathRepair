N = int(input())
A = [int(a) for a in input().split()]
B = [int(a) for a in input().split()]

x = sum(B) - sum(A)
if x >= 0 and sum([max(a-b, a+b&1) for a, b in zip(A, B)]) <= x:
    print("Yes")
else:
    print("No")