k = int(input())
s= (input())
n = len(s)
count = [0]*(n+1)
count[0]+=1
ini = 0
if(k==0):
    ans =0
    ini =0
    s= s+"1"
    print(s)
    for i in range(n+1):
        if( s[i] == "1"):
            ans =ans+ ini*(ini+1)//2
            ini=0
        else:
            ini+=1
        
    print(ans)
else:
    for i in s:
        if(i=="1"):
            ini +=1
        count[ini]+=1
    ans = 0
    for i in range(k,n+1):
        ans+=count[i]*count[i-k]
    print(ans)

    
