import sys
input=sys.stdin.readline
n=int(input())
a=[int(i) for i in input().split() if i!='\n']
freq=[0]*(n)
q=int(input())
store=dict()
init=sum(a)
diff=0
for i in range(q):
    s,t,u=map(int,input().split())
    if (s,t) not in store:
        if u!=0:
            store[(s,t)]=u-1
            if freq[u-1]<a[u-1]:
                diff+=1
            freq[u-1]+=1
    else:
        if u>0:
            if freq[u-1]<a[u-1]:
                diff+=1
                freq[u-1]+=1
        if freq[store[(s,t)]]-1<a[store[(s,t)]]:
            diff-=1
        freq[store[(s,t)]]-=1
        #print(freq[store[(s,t)]],store[(s,t)])
        if u>=0:
            store[(s,t)]=u-1
        else:
            del store[(s,t)]
            
    sys.stdout.write(str(init-diff)+'\n')
        
        
    
