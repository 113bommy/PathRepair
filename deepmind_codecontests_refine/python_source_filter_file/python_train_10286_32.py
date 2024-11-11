n=int(input())
p=list(map(int,input().split()))
g=sum((1 for i in range(n) if i+1 !=p[i]))
print("YNeos"[::2] if g==2 or g==0 else "YNeos"[1::2])