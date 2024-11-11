a = [int(x) for x in input().split()]
p = [int(x) for x in input().split()]
n = a[0];
k = a[1];
c = 0;
for i in range(0,n):
    if(p[i] + k < 5):
        c = c+1;
print(c//3);