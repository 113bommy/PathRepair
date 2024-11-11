t = int(input())
a = []
for i in range(t):
  a +=[list(map(int,input().split()))]
a.sort()  
for i in range (t - 1):
  if(a[i][1]>a[i+1][1]):
    print("Happy Alex")
    exit()
print("Poor Alex")       







