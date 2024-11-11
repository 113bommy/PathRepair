a,b,c,d,e=map(int,input().split())
if a*b+2*d>a*c+2*e:
    print("First")
elif a*b+2*d<a*c+2*e:
    print("Second")
else:
    print("Friendship")