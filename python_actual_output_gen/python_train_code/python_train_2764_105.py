n=int(input())
l=list(map(int,input().split()))
s=sum(l)/(n*100)
print(round(s,12))