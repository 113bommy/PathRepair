n=int(input())
s=[int(input()) for _ in range(n)]
print(int(sum(s) - max(s)/2))