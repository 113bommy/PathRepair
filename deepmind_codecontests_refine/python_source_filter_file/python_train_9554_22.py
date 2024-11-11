h,w,m = map(int,input().split())
hw = [list(map(int,input().split())) for _ in range(m)]
hlist = [0]*(h+1)
wlist = [0]*(w+1)
for x,y in hw:
    hlist[x]+=1
    wlist[y]+=1

hmax=max(hlist) 
h_index = [n for n, v in enumerate(hlist) if v == hmax]
wmax=max(wlist)
w_index = [n for n, v in enumerate(wlist) if v == wmax]

count = sum(x in h_index and y in w_index for x,y in hw)
print(hmax+wmax-(len(h_index)*len(w_index)==count))