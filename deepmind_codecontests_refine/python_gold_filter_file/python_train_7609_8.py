n=int(input())
l=list(map(int,input().split()))
m=max(l)-min(l)+1
print(m-n)