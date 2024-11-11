l=list(map(int,input().split()))
n=int(input())
print(sum(l)+max(l)*2**n-max(l))