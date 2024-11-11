x=list(map(int,input().split()))
k=int(input())
print(max(x)*(2**k)+sum(x)-max(x))