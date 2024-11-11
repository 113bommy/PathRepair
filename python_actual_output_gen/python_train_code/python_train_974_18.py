n=int(input())
d=list(map(int,input().split()))
s=sum(d)
print(sum([x*(d-x) for x in d])//2)