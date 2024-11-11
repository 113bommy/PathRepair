s=list(input().split())
a,b=map(int,input().split())
print(a,b-1 if s.index(input())==1 else a-1,b)