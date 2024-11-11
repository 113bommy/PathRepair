import sys
input=sys.stdin.readline
s=[i for i in input() if i!='\n']
freq=[[0 for i in  range(26)] for _ in range(len(s))]
for i in range(len(s)):
    freq[i][ord(s[i])-97]+=1
    if i>0:
        for j in range(26):
            freq[i][j]+=freq[i-1][j]
#print(freq)
q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    count=0
    for j in range(26):
        temp=freq[r-1][j]
        if l>1:
            temp-=freq[l-2][j]
        if temp:
            count+=1
    #print(sum(freq[r-1])-minus)
    if r==l  or count>=3 or s[l-1]!=s[r-1]:
        print("Yes")
    else:
        print("No")
