n,k,m=map(int,input().split())
a=list(map(int,input().split()))
l=[[]for i in range(m)]
x=True
for i in a :
      l[i%m].append(i)
      if len(l[i%m])>=k:
            print("YES")
            for j in l[i%m]:
                  print(j,end=" ")
            x=False
            break
if x:
      print("NO")