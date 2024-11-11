a=int(input())
b=list(map(int,input().split()))
c=sorted(b)
print("Yes" if sum(b[:-2])>b[-1] else "No")