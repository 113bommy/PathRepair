a=list(map(int,input().split()))
k=int(input())
b=sorted(a)
print(b[0]+b[1]+b[2]*2**k)