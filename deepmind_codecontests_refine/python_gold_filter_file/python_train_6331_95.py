n=int(input())
p=list(int(input()) for i in range(n))
print(int(sum(p)-max(p)//2))