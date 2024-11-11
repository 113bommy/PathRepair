
n=int(input())
a=str(input())
a=list(map(int, a.split()))
print(max(a)-min(a)-n+1)
