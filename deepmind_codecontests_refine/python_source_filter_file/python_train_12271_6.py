n=int(input())
r=[0]*n
for i in range(n):
    r[i]=sorted(list(map(int,input().split())))
for i in range(n):
    print("Yes" if r[i][0]**2+r[i][1]**2==r[i][2]**2 else "No")