import math
mod=1000000007
n=int(input())
iwashi_group={}
count=0

#傾きを第1象限(True)と第4象限(False)の座標で管理する
for i in range(n):
    a,b=map(int,input().split())
    
    if a*b>0:
        GCD=math.gcd(abs(a),abs(b))
        iwashi=(abs(a)//GCD,abs(b)//GCD)
        flag=True
    
    elif a*b<0:
        GCD=math.gcd(abs(a),abs(b))
        iwashi=(abs(b)//GCD,abs(a)//GCD)
        flag=False

    elif a==0 and b==0:
        count+=1
        continue

    elif a==0:
        iwashi=(0,1)
        flag=True
    
    elif b==0:
        iwashi=(0,1)
        flag=False
  
    if iwashi in iwashi_group:
        if flag:
            iwashi_group[iwashi][0]+=1
        else:
            iwashi_group[iwashi][1]+=1
    else:
        if flag:
            iwashi_group[iwashi]=[1,0]
        else:
            iwashi_group[iwashi]=[0,1]

ans=1
for a,b in iwashi_group.values():
    ans=ans*(2**a+2**b-1)%mod

print(ans+count-1)