a = []
n = int(input())
x1,x2 = map(int,input().split())
for i in range(n):
    k,b = map(int,input().split())
    c,d = k*x1+b,k*x2+b
    a.append([c,d])
def f(a):
    return a[1]
a.sort(key=f)
for i in range(1,len(a)):
    if a[i][0]<a[i-1][0] and a[i][1]>a[i-1][1]:
        print('Yes')
        quit()
print('No')
