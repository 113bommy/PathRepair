n,w,v,t,y=map(int,input().split())
s=2*t +n*w
q=2*y +n*v
if s==q:
    print("Friendship")
elif s>q:
    print("First")
else:
    print("Second")