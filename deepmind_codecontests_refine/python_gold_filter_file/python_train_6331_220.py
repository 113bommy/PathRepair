n=int(input())
a=[int(input()) for _ in [0]*n]
print(sum(a)-max(a)//2)