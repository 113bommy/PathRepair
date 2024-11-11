n=int(input())
a=[]
for i in range(n):
        c,d=map(int,input().split())
        a.append([c,d])
a.sort()
f=1
for i in range(n-1):
        if a[i+1][1]>a[i][1]:
                f=0
                break
if f==1:
        print("Poor Alex")
else:
        print("Happy Alex")
                
