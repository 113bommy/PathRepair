def swap(z,x,y):
    temp = z[x];
    z[x] = z[y];
    z[y] = temp;

    
n = input();
n = int(n);
a = input().split();
for k in range(n):
    a[k] = int(a[k]);

    
b = len(a);
for i in range(b):
    temp = i;
    for j in range(i,b):
        if a[temp]>a[j]:
            
            
            
            temp = j;
    if temp!=i:
        swap(a,temp,i);
        
flag = 0;        
for i in range(0,n-1,2):
    d = a[i+1]-a[i];
    print(d);
    
    flag = flag+d;
print(flag);
    


            