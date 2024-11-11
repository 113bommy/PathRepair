import sys
input=sys.stdin.readline
t=int(input())
p2=[]
k=1
while k<10**18:
    p2.append(k)
    k*=2
for _ in range(t):
    n=int(input())
    sn=str(n)
    min_cnt=10**9
    for x in p2:
        xx=str(x)
        j=0
        cnt_del=0
        cnt_add=0
        for i in range(len(xx)):
            if j>=len(sn):
                cnt_add+=len(xx)-i
                break
            if xx[i]==sn[j]:
                j+=1
            else:
                while j<len(sn) and xx[i]!=sn[j]:
                    j+=1
                    cnt_del+=1
                if j<len(sn):
                    j+=1
                else:
                    cnt_add+=len(xx)-i
                    break
        if len(sn)>len(xx):
            cnt_add+=len(sn)-j
        cnt=cnt_del+cnt_add
        #print(x,cnt)
        min_cnt=min(min_cnt,cnt)
    print(min_cnt)