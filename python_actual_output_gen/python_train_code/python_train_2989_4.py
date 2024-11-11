n = int(input())
a = sorted(list(map(int,input().split())))



for i in range(n-1) :
  if a[i] + 1 != a[i+1] :
    print(a[i] + 1)
    exit() 

print(a[-1]+1)
