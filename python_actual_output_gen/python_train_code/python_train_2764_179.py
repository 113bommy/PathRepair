n = int(input())
a = list(map(int,input().split()))
for i in range(len(a)):
    a[i] = a[i]/100
print((sum(a)/4)*100)
