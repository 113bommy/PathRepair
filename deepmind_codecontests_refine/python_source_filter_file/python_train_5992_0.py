n=int(input())
a=[int(i) for i in input().split()]
b=[]
for i in range(n):
    b.append([a[i],i+1])
b=sorted(b)
for i in range(int(n/2)):
    print(b[i],b[len(b)-i-1])