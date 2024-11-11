n=int(input())
s=[int(input()) for _ in range(n)]
print(sum(s)-max(s)//2)