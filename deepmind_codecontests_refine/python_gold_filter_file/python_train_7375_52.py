n=int(input())
l=sorted(list(map(int,input().split())),reverse=0)
print(sum(l[n::2]))