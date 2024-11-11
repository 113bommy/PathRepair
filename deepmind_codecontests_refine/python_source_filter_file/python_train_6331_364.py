n=int(input())
p=[int(input()) for i in range(n)]
q=max(p)
print(sum(p)-q+q/2)
