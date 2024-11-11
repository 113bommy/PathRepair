n=int(input())
a=[2,1]
for i in range(n-2):
  a+=[sum(a[-2:])]
print(a[n-1])