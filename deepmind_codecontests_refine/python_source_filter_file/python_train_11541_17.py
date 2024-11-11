A, B, C = map(int, input().split())
print("Yes" if any((A*i)%B==C for i in range(B)) else "No")