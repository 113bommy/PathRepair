t=int(input())
for i in range(t):
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
 
    if sum(a)<=s:
        print(0)
    else:
        pref=[a[0]]
        for i in range(1,len(a)):
            pref.append(pref[-1]+a[i])
 
        x,y,c=0,0,0
        for i in range(len(pref)):
            if pref[i]>s:
                y=i
                break
            else:
                x=max(x,a[i])
                c+=1
 
        ans=c-1
        for i in range(y,len(pref)):
            if pref[i]-x<=s:
                ans+=1
            else:
                break
 
        temp,r=0,0
        for i in range(len(a)):
            if i==y:
                pass
            else:
                temp+=a[i]
                if temp<=s:
                    r+=1
                else:
                    break
 
        if ans>c and ans>=r:
            print(a.index(x)+1)
        elif r>c and r>=ans:
            print(y+1)
        else:
            print(0)