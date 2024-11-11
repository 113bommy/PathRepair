n=input()
a=[0]*((len(n)))
k=0
for i in range(1,len(n)):
    if n[i-1]==n[i]:
        k+=1
    a[i]=k
print(a)
t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    print(a[m-1]-a[n-1])