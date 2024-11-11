n=int(input())
a=list(map(int,input().split()))
a.sort()
try:
    while a[0]==a[1]:
        a.pop(0)
        n-=1
    while a[n-1]==[n-2]:
        a.pop()
        n-=1
    print(len(a)-2)
except:
    print(0)
