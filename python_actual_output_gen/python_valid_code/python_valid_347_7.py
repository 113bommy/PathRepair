input()
A = list(map(int, input().split()))
B = list(map(int, input().split()))

if len(A) >= len(B):
    print("Yes")
else:
    print("No")    