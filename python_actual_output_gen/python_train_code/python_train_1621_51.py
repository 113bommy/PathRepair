n=int(input())
d=sorted(list(map(int,input().split())))
print(d[n]-d[n-1])