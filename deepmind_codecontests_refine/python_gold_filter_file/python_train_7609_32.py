n=int(input())
a=list(map(int,input().split()))
r=(max(a)-min(a)+1)
print(r-n)