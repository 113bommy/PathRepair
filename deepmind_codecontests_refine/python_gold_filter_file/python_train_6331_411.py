n=int(input())
l=[int(input()) for _ in range(n)]
print(sum(l)-max(l)//2)