n=int(input())
c=list(map(int,input().split()))
a,b=map(int,input().split())
print(sum(c[:abs(b-a)]))
