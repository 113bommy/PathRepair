w,a,b=map(int,input().split())
print(b-(a+w) if b>a else a-(b+w) if b<a else 0)