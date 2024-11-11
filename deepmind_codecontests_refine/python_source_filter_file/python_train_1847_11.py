
k=int(input())
v=[]
for i in range(0,k):
    sum=0
    n=int(input())
    a=[]
    s=input()
    s=s.split(" ")
    for j in range(0,n):
        now=int(s[j])
        a.append(now)
        sum+=now
    for j in range(0,n):
        v.append([sum-a[j],i+1,j+1])
        
v.sort()

for i in range(0,k-1):
    if v[i][0]==v[i+1][0] and v[i][1]!=v[i+1][1]:
        print("YES")
        print(v[i][1]," ",v[i][2])
        print(v[i+1][1]," ",v[i+1][2])
        break
else:
    print("NO")
