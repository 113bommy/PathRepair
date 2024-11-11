n,k,x=[int(x) for x in input().split()]
a =[int(x) for x in input().split()]
sum = 0
for i in range(len(a)-k):
        sum = sum + a[i]
print (sum + k*x)