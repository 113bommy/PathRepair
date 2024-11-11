x=int(input())
str=input()
t=0
if len(str)==0:
    exit(print("YES"))
d={ i : [0] for i in "abcdefhijklmnopqrstuvwxyz"}
for i in d :
    #print(i)
    d[i]=str.count(i)
    if d[i]>1 :
        t=1 
        break
if (1==t) :
    print("YES")
else :
    print("NO")