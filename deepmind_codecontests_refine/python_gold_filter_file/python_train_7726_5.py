import sys
from collections import defaultdict
def get(dic,tar,b):
    #print(dic,'dic')
    #print(tar,'tar')
    #print(b,'b')
    s=bin(tar)
    n=len(s)
    num=1<<(n-2)
    ans=0
    temp=defaultdict(int)
    for i in range(n-1,1,-1):
        if s[i]=='1':
            num=1<<(n-i-1)
            #print(num,'num',ans,'ans')
            if dic[num]!=0:
                dic[num]-=1
            else:
                for j in dic:
                    temp[j]=dic[j]
                #print(1<<(n-i-1),'num',i,'i')
                rem=1<<(n-i-1)
                num=1<<(n-i-1)
                while rem>0 and num>0:
                    if dic[num]!=0:
                        x=rem//num
                        if dic[num]>=x:
                            dic[num]-=x
                            rem=0
                        else:
                            m=num*dic[num]
                            rem-=m
                            dic[num]=0
                            num=num//2
                    else:
                        num=num//2
                if rem!=0:
                    count=0
                    for j in temp:
                        dic[j]=temp[j]
                    num=1<<(n-i-1)
                    rem=1<<(n-i-1)
                    while num<b+1:
                        if dic[num]!=0:
                            dic[num]-=1
                            ans+=count
                            num=num//2
                            while num>=rem:
                                dic[num]+=1
                                num=num//2
                            break
                        else:
                            num=num*2
                            count+=1
                    if num>=b+1:
                        return -1
    return ans
t=int(sys.stdin.readline())
for _ in range(t):
    tar,n=map(int,sys.stdin.readline().split())
    arr=list(map(int,sys.stdin.readline().split()))
    dic=defaultdict(int)
    for i in arr:
        dic[i]+=1
    print(get(dic,tar,max(arr)))
