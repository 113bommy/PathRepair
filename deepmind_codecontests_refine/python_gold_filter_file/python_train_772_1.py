import sys
#fin=open('F:/OJ/OJ/in.txt','r')
#sys.stdin=fin

str=input()
k=int(input())
ans=0
if(k>=len(str)):
    print((k+len(str))//2*2)
    exit()
for i in range(len(str)):
    for j in range(0,i+1):
        len1=len(str[j:i+1])
        len2=len(str[i+1:])
        minn=min(len1,len2)
        #print( i,j)
        #print(len1,len2)
        if(str[j:j+minn]==str[i+1:i+1+minn]):
            if(minn==len1):
                ans=max(ans,len1*2)
            elif(k+len2>=len1):
                ans=max(ans,len1*2)
                
print(ans)
