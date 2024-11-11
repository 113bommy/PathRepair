n=int(input())
l=list(map(int,input().split()))
print("Yes" if sum(l)>2*max(l) else "No")