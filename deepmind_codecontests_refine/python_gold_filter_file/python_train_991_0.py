n=int(input())
a=[0]
b=list(map(int,input().split()))
a.extend(b)
a.append(90)

for i in range(1,n+2):
    if a[i]-a[i-1]>15:
        print(a[i-1]+15)
        break
else:
    print(a[n+1])