n=input()
l=sorted(map(int,input().split()))
print("Yes" if sum(l[:-1])>l[-1] else "No")