
a=list(sorted(map(int,input().split())))
k=int(input())
print(sum(a)+a[-1]*2*k-a[-1])