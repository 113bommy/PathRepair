n=int(input())
k = [int(input()) for i in range(n)]
print(int((sum(k)-max(k)//2))