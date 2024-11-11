n=input()
ls=list(map(int,input().split()))
print(sum(max(ls)-l for l in ls))
