n,m=list(map(int,input().split()))
l=list(map(int,input().split()))
l.sort(reverse=True)
print("No") if l[m-1]<sum(l)/(4*m) else print("Yes")