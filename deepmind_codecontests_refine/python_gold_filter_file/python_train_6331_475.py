N=int(input())
L=[int(input()) for i in range(N)]
print(sum(L)-max(L)//2)