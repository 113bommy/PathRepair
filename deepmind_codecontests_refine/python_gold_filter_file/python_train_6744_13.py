n=int(input())
l=list(map(int,input().split()))
a=[0]*n
for i in l:
    a[i-1]+=1
for i in a:
    print(i)