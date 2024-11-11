n=int(input())
a=list(map(int,input().split()))
c=max(a)-min(a)+1
print(c-n)