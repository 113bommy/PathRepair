n=int(input())
l=[int(input()) for _ in range(n)]
print(sum(l)-int(0.5*max(l)))