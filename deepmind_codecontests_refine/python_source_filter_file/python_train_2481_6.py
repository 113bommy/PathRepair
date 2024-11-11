n=int(input())
d,x=map(int,input().split())
print(x+sum(d//int(input()) for _ in range(n)))