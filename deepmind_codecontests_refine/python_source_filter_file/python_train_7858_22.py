n = int(input());
a = [int(x) for x in input().split()];
c = 1;
max = 0;
for i in range(0,n-1):
    if(a[i] <= a[i+1]):
        c = c+1;
    else:
        c = 1;
    if(c > max):
        max = c;
print(max);