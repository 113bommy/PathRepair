a=int(input())
f = list(map(int,input().split()))
b=[]
ave=sum(f)/a
for i in f:
    diff=abs(i-ave)
    b.append(diff)
print(b.index(min(b)))