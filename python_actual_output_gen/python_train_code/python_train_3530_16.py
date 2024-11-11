n=int(input())
d=list(map(int,input().split()))
print(n-d.count(min(d))-d.count(max(d)))