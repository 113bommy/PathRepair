n=int(input())
print(sum(sorted(map(int,input().split()),reverse=True)[1:n*2+1:2]))