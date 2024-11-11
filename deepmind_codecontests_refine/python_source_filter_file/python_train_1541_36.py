a,s,d=map(int,input().split())
print("bust" if sum([a,s,d])<=22 else "win")