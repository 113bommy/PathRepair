h,w,k=map(int,input().split())
L=[0]*w
f=1
past=0
for i in range(h):
    s=list(input())
    for j in range(w):
        if '#' not in s:
            L.append(L[i*w+j])
        else:
            if s[j]=='.':
                L.append(f)
            else:
                if past==1:
                    f += 1
                else:
                    past=1
                L.append(f)
            if j==w-1:
                f += 1
                past=0

L=L[w:(h+1)*w]
zero=L.count(0)
z=zero//w
for i in range(w):
    num=L[zero+i]
    for j in range(z):
        L[i+(z-1)*w]=num

for i in range(h):
    ans=L[w*i:w*(i+1)]
    ans=[str(x) for x in ans]
    print(' '.join(ans))