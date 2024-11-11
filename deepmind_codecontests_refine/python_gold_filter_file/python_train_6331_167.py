n=int(input())
k = [int(input()) for i in range(n)]
print(sum(k)-max(k)//2)