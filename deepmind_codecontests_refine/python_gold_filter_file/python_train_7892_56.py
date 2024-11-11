a=list(map(int,input().split()))
k=int(input())
print(sum(a)+(2**k-1)*max(a))