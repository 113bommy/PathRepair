s,c=map(int,input().split())
a=min(s,c//2)
c-=s*2
a+=c//4
print(a)