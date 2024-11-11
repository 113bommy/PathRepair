h,w=map(int,input().split())
print(-(-(h*w)//2) if h!=1 or w!=1 else 1)