N = int(input())
A = map(int,input().split())

if sum(A) % 2 == 0:
    print("Yes")
else:
    print("No")