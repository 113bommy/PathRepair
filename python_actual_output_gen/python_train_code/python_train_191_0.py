x,y=map(int,input().split());
s=input();
s=list(s);
s.sort();print(s);
d=dict();
for i in range(97,123):
    d[chr(i)] =i-96;
sum=0;t=-1;c=0;w=0;
for i in s:
    print(i,s);
    if (d[i] - t >=2) :
        c+=1;
        sum+=d[i];
        t=d[i];
        if (c==y):
            w=1;
            break;
    else :
        continue ;
if (w==1):
 print(sum);
else :
    print("-1");