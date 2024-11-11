a,b,c,d= map(int,input().split(" "))

l=[a,b,c]
#print (l)
#print (d)
l.sort()
t=0
if (d-(l[1]-l[0]))>0:
    t+=(d-(l[1]-l[0]))
if (d-(l[2]-l[1]))>0:
    t=+(d-(l[2]-l[1]))
print (t)
            