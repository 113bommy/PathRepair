n=int(input())
p=[int(input()) for i in range(n)]
q=max(p)
print(int(sum(p))-int(q)/2)
