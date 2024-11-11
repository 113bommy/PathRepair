n=int(input())
d,x=map(int,input().split())
print(x+n+sum(d//int(input()) for _ in range(n)))