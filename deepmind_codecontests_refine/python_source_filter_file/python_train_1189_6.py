n,m=map(int,input().strip().split())
mn=min(n,m)
n-=mn;
m-=mn;

st="";
for i in range(mn):
    st2=str("10")
    st+=st2;
#print(st);

if(n!=0):
    if(n==1):
        st="0"+st;
        print(st);
    else:
        print("-1");
else:
    #print("m=",m);
    ans="";
    for i in range(0,len(st)-1,2):
        if(m==0):
            #print("ram");
            ans+=st[i:]
            break;
        if(st[i]=='0' and st[i+1]=='1'):
            ans+="011";
            m-=1;
        elif(st[i]=='1' and st[i+1]=='0'):
             ans+="110";
             m-=1;
        else:
            ans+=st[i];
            ans+=st[i+1];
#print(m)
#print(len(st))
    if(m==0):
     print(ans)
    elif(ans[-1]=='0'):
     #print("hello\n")
     if(m==1):
      ans+="1";
      m-=1;
     elif(m==2):
      ans+="11";
      m-=2;
     if(m!=0):
      print("aaaa")
      print(-1);
     else:
      print(ans);

