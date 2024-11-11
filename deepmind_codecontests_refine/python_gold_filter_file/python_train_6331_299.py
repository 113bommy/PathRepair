N=int(input())
l=[int(input()) for _ in range(N)]
print(sum(l)-max(l)//2)