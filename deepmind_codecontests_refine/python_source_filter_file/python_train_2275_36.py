N = int(input())
A = list(map(int,input().split()))
print("Yes" if sum(A)%2==0 else "No")