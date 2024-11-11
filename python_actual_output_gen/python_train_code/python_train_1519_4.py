n = int(input())
a = [i for i in map(int, input().split())]
sum1 = sum(a[1::2])
sum2 = sum(a[1::2])
sol = 0;
if sum1==sum2:sol+=1
for i,j in enumerate(a[1:], 1):
    if i%2==1:sum1-=a[i];sum1+=a[i-1]
    else:sum2-=a[i];sum2+=a[i-1]
    if sum1==sum2:sol+=1
print(sol)
