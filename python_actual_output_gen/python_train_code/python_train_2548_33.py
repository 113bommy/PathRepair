n=int(input())
print(sum(sorted(list(map(int,input().split())))[2*n+1:1:-2]))