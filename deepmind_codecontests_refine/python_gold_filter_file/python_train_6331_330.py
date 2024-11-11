n=int(input())
li=[int(input()) for _ in range(n)]
print(sum(li)-max(li)//2)