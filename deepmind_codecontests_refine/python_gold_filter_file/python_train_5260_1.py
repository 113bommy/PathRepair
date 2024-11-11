length,distance=map(int,input().split())
word=input()
dist=0
dsf=0
for i in word:
    a=ord(i)
    dist+=max(a-97,122-a)
if dist<distance:print(-1)
else:
    newWord=''
    for i in word:
        a=ord(i)
        if a<109:
            if distance-dsf>=122-a:
                newWord+='z'
                dsf+=122-a
            else:
                newWord+=chr(a+max(0,(distance-dsf)))
                dsf=dist
        else:
            if distance-dsf>=a-97:
                newWord+='a'
                dsf+=a-97
            else:
                newWord+=chr(a-max(0,(distance-dsf)))
                dsf=dist
    print(newWord)