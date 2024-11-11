[n,x,y] = list(map(int, input().split(" ")))
a = list(map(int,input()[n-x+1:n]))
b = [0]*(x-1)
b[x-y-2]=1
count=0
for i in range(x-1):
      if a[i]!=b[i]:
            count+=1
print(count)