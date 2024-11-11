t = int(input());
p = 0;

while t>0:
    s , a , b = input().split();

    a = int(a);
    b = int(b);

    if b>a and a>=2400:
        p = 1;
    t-=1;

if p==1:
    print("YES");

else:
    print("NO");
        

            

        
