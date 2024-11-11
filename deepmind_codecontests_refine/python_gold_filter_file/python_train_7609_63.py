n=int(input())
l=list(map(int,input().split()))
x=max(l)-min(l)+1
print(x-n)