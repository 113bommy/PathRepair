n=int(input())
d=list(map(int,input().split()))
D=sorted(d)
print(D[(n//2)+1]-D[(n//2)-1])