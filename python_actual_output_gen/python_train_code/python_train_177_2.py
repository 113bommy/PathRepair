s,v1,v2,t1,t2=map(int,input().split())
res1=(v1*s)+(t1*2)
res2=(v2*s)+(t2*2)
print(res1,res2)
if (res1<res2):
    print("First")
elif (res2<res1):
    print("Second")
else:
    print("Friendship")