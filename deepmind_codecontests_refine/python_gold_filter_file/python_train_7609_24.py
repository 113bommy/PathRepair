n=int(input())
l=list(map(int,input().split()))
print(max(l)-min(l)-len(l)+1)