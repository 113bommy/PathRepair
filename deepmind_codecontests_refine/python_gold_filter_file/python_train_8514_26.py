import sys
s=str(input())
t=str(input())

for i in range(len(t)):
    if s.find(t[i])==-1:
        print(-1)
        break
else:
    a=0
    count=0
    for k in t:
        if k in s[a:]:
            a=s.find(k,a)+1
        else:
            count+=1
            a=s.find(k)+1
    print(count*len(s)+a)