N = int(input())
S = input()
print("Yes" if N[0:N/2-1] == N[N/2+1:] else "No")