n=int(input())
d=sorted(list(map(int,input().split())))

print(d[n//2+1]-d[n//2-1])