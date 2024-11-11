t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    st=input()
    s=list(st)
        
    for j in range(min(m,n)):
        c=0
        for i in range(n):
            if st[i]=="0":
                if i==0:
                    if st[1]=='1':
                        s[0]='1'
                        c+=1
                        
                elif i==(n-1):
                    if st[n-2]=='1':
                        s[n-1]='1'
                        c+=1
                        
                        
                else:
                    if(st[i-1]=='1' and st[i+1]=='0') or (st[i-1]=='0' and st[i+1]=='1'):
                        s[i]="1"
                        c+=1
        st="".join(s)
        if c==0:
            break
    print(st)
        