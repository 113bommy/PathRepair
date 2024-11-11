# array=[4,2,2,7,8,1,2,8,10]
# i=0
# j=0
# requiredsum=8
# n=9
# currentsum=0
# currentlength=0
# minlength=99
# while(j<n):
#     currentsum+=array[j]
#     if (currentsum>=requiredsum):
#         currentlength=j-i+1
#         minlength=min(minlength,currentlength)
#     currentsum-=array[i]
#     i+=1
#     j+=1
# print(currentlength)
#longest substring with atmost k different characters
'''
s="lauda"
k=3
start=0
contains={}
maxlen=0
for end in range(len(s)):
    if not s[end] in contains:
        contains[s[end]]=0
    contains[s[end]]+=1
    while(len(contains))>k:
        left=s[start]
        contains[left]-=1
        if contains[left]==0:
            del contains[left]
        start+=1
    maxlen=max(maxlen,end-start+1)
print(maxlen)
'''
##word wrap
n,m=map(int,input().split())
l1=[]
for i in range(n):
    l1.append(input())
minx=miny=99999999999
maxx=maxy=-99999999999
for i in range(n):
    for j in range(m):
        if l1[i][j]=='B':
            minx=min(minx,i)
            miny=min(miny,j)
            maxx=max(maxx,i)
            maxy=max(maxy,j)
print((minx+miny)//2+1,end=' ')
print((maxx+maxy)//2+1)
