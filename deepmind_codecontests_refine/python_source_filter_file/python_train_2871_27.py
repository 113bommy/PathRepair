n = int(input())
ai = list(map(int,input().split()))
ans = [str(ai[(n-i-1) * ((i+1 + (n%2 == 0 and i >= n//2)) % 2) + i * ((i + (n%2 == 0 and i > n//2)) % 2)]) for i in range(n)]
print(" ".join(ans))
