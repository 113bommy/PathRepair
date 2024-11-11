n=int(input())
p=[int(input()) for i in range(n)]
m=max(p)
print(int(sum(p)-m/2))