w,h,k=map(int,input().split())
s=[[0]*h for i in range(w)]
x=0
for i in range(k):
    for a in range(w):
        for b in range(h):
            if a==x or b==x or a==w-x-1 or b==h-x-1:
                if a!=x-1 and a!=w-x and b!=x-1 and b!=h-x:
                    s[a][b]=1
    x+=2
print(sum([sum(i) for i in s]))