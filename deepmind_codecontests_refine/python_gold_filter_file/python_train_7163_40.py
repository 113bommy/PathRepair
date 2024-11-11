a,b,c=map(int,input().split())
q=min(b,c)
w=b+c-a
print("{} {}".format(q,max(0,w)))
