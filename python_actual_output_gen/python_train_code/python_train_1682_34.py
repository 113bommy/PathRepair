h,w=map(int,input().split())
print(int(((h*w/2,w*(h//2)+(w+1)//2)[h&1],1)[h==1]))