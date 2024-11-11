def finddistance(a,b):
    k1  = abs(122-ord(b)+ord(a)-96)
    k2 = abs(ord(b)-ord(a))
    k3 = abs(122-ord(a)+ord(b)-96)
    k4 = abs(ord(a)-ord(b))
    return min([k1,k2,k3,k4])
n,p =map(int,input().split())
s = list(input())
a = []
c=  0
d = 0
count = 0
for i in range(n//2):
    if i==n-i-1:
        pass
    elif s[i]!=s[n-i-1]:
        a.append(i)
div = n//2   
if p>div:
    p = n-p+1
if len(a)==0:
    print(0)
else:
    p-=1
    last=  10**6
    first = 10**6
    if a[-1]>=p:
        last= a[-1]-p  
    if a[0]<=p:
        first  = p-a[0]
    mini = min(last,first)
    p1 = p
    if mini == first:
        c= 0
        while(p1>=a[0]):
            if count==0:
                count = 1
            else:
                c+=1
            if s[p1]!=s[n-p1-1]:
                c+=finddistance(s[p1],s[n-p1-1])
                s[p1]=  s[n-p1-1]
            p1-=1
        d = 0
        count = 0
        p1+=1
        if a[-1]>p:
            while(p1<=a[-1]):
                if count == 0:
                    count=1
                else:
                    d+=1
                if s[p1]!=s[n-p1-1]:
                    d+=finddistance(s[p1],s[n-p1-1])

                    s[p1]=  s[n-p1-1]
                p1+=1
    else:
        c = 0
        while(p1<=a[-1]):
            if count == 0:
                count=1
            else:
                c+=1
            if s[p1]!=s[n-p1-1]:
                c+=finddistance(s[p1],s[n-p1-1])
                s[p1]=  s[n-p1-1]
            p1+=1
        d = 0
        p1-=1
        count= 0
        if a[0]<p:
            while(p1>=a[0]):
                if count == 0:
                    count = 1
                else:
                    d+=1
                if s[p1]!=s[n-p1-1]:
                    d+=finddistance(s[p1],s[n-p1-1])
                    s[p1]=  s[n-p1-1]
                p1-=1
print(c+d)