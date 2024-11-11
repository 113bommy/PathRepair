import bisect

H,W,K=map(int,input().split())
s=[""]*H
ans=[[0]*W for _ in range(H)]
St=[0]*H#i行目にイチゴがあるか？
St2=[]


for i in range(H):
    s[i]=input()
    if "#" in s[i]:
        St[i]=1
        St2.append(i)
        
    
    
a=1
#i行目，aからスタートして埋める
for i in range(H):
    if St[i]==1:
        flag=0
        for j in range(W):
            if s[i][j]=="#":
                if flag==0:
                    flag=1
                else:
                    a+=1
            ans[i][j]=a
        a+=1
        

for i in range(H):
    k=bisect.bisect_left(St2,i)
    #近いところを参照したいけど参照したいけど，端での処理が面倒
    if k!=0:
        k-=1
    if St[i]==0:
        ans[i]=ans[St2[k]]
        
for i in range(H):
    print(" ".join(map(str, ans[i])))