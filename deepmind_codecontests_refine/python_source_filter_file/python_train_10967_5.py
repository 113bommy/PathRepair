

n,k = map(int,input().split())



t = list(map(int,input().split()))

u=0

for i in range(len(t)):
    if u<k:
        if t[i]>0 and i%2!=0:
            if i==0:
                if t[i]-1!=t[i+1]:
                    u+=1
                    t[i]-=1
                    if u==k:
                        print(*t)
                        break
            elif i==len(t)-1:
                if t[-1]-1!=t[-2]:
                    u+=1
                    t[i]-=1
                    if u==k:
                        print(*t)
                        break
            else:
                if t[i]-1!=t[i-1] and t[i]+1 !=t[i+1]:
                    u+=1
                    t[i]-=1
                    if u==k:
                        print(*t)
                        break

