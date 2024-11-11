n,t=map(int,input().split())
l=list(map(int,input().split()))
a=0
for i in range(n):
    if l[i]<86400:
        a+=86400-l[i]
    if a>=t:
        print(i)
        break
