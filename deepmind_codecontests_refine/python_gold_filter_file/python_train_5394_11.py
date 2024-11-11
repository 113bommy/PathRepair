n=int(input())
l=list(map(int,input().split()))
l=sorted(l)
print("Yes"if sum(l[:-1])>l[-1] else "No")