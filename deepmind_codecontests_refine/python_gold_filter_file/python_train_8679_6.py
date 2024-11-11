n = int(input())
a = [0]+sorted(list(map(int,input().split())))



for i in range(n) :
  if a[i] + 1 != a[i+1] :
    print(a[i] + 1)
    exit() 

print(a[-1]+1)