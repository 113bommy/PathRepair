a,b,c = map(int,input().split())
k = int(input())
print(sum(a,b,c)+(max(a,b,c)*(2**k-1)))