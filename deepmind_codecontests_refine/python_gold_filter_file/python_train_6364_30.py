# import sys
# input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
b=[]
for i in range(min(a),max(a)+1):
    s=0
    for j in range(n):
        if i>a[j]:
            s+=i-a[j]-1
        elif i<a[j]:
            s+=a[j]-i-1
    b.append([s,i])
c=min(b)
print(c[1],c[0])