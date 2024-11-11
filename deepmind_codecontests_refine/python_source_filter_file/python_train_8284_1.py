s=input()
ans=0
j=0
cnt1=0
cnt2=0
for i in range(0,len(s)):
    if i>=j:
        while i<len(s) and s[i]=='a':
            cnt1=cnt1+1
            i=i+1
        while i<len(s) and s[i]=='b':
            cnt2=cnt2+1
            i=i+1
        j=i;
        if cnt1>0 and cnt2>0:
            ans=ans + cnt2
            bb= cnt2*2
            cnt1=cnt1-1
            ans = ans + bb*(pow(2,cnt1,1000000007)-1)
            #print(ans)
        cnt2=0
print(ans%1000000007)
    
        
    