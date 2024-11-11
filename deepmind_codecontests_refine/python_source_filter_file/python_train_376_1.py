a = int(input())
b = int(input())
k = min(a,b)
sum1=0
sum2=0
l = max(a,b)
z = l+k
x = z//2
sum1 = (x-k)/2*(x-k+1)
sum2 = (l-x)/2*(l-x+1)
result = sum1+sum2
print(result)
