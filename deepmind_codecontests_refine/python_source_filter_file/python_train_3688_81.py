x=int(input())
d=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(d[:(b-a)]))