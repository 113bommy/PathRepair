s,v1,v2,t1,t2=[int(x) for x in input().split()]
an1=s*v1+2*t1
an2=s*v2+2*t2
if(an1<an2):
    print("First")
elif(an2>an1):
    print("Second")
else:
    print("Friendship")
