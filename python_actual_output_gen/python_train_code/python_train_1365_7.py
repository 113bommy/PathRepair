s=str(input())
t=str(input())
l=["a","e","i","o","u"]
count=0
if len(s)>len(t):
    print("No")
else:
    for i in range(min(len(s),len(t))):
        if (s[i] in l) and (t[i] in l):
           # print(" yt")
            count+=1
        elif s[i] not in l and t[i] not in l:
            #print("hfg")
            count+=1
    if count==min(len(s),len(t)):
        print("Yes")
    else:
        print("No")