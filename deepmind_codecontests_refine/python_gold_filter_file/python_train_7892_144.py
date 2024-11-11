l=list(map(int,input().split()))
k=int(input())

print(sum(l)+max(l)*(2**k)-max(l))
