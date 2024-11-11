a,b,c,d=map(int,input().split());print("YNeos"[abs(c-b)>d or abs(b-a)>d or abs(a-c)>d::2])
