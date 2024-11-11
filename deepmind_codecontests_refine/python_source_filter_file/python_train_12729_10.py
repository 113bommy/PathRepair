s=list(x for x in input())
s1=list(x for x in input())
s2=list(x for x in input())
s=s+s1
#print(s)
#print(s1)
if(len(s)==len(s1)):
    for i in s:
        if(s.count(i)!=s2.count(i)):
            print("NO")
            break
    else:
        print("YES")
else:
    print("NO")
