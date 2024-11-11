t=int(input())
for i in range(t):
    n,x=input().split(); n=int(n); x=int(x);
    s=input();
    weights=[];
    bal=0;
    for i in range(len(s)):
        if s[i]=='0':
            bal=bal+1;
            weights.append(bal);
        else:
            bal=bal-1;
            weights.append(bal);
    if weights[len(s)-1]==0:
        if x in weights:
            print(-1);
        else: 
            print(0);
    elif weights[len(s)-1]<0:
        y=weights[len(s)-1];
        count=0;
        if x==0:
            count+=1;
        for k in weights:
            if (k-x)>0 and (k-x)%y==0:
                count+=1;
        print(count);
    elif weights[len(s)-1]>0:
        y=weights[len(s)-1];
        count=0;
        if x==0:
            count+=1;
        for k in weights:
            if (x-k)>0 and (x-k)%y==0:
                count+=1;
        print(count);
        