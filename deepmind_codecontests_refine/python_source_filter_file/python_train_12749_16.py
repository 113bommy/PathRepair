s = (input().split())
n = int(s[0])
l = int(s[1])
#  = int(input())

a = list(map(int,input().split()))

a.sort()

d= 0.0
if(a[0])/2 >d:
    d = float(a[0])
    
for i in range(n-1):
    x = a[i+1] - a[i]
    if (x/2)>d:
        d = float(x/2)
if(l-a[n-1])/2 >d:
    d = float((l-a[n-1])/2)

# print ('%.2f'%a)
print('%.10f'%d)