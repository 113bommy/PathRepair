n, m  =  map(int, input().split())
p     =  list(map(int, input().split()))

ld   =  {}
rd   =  {}

def push(d, x):
    if x not in d:
        d[x] = 0
    d[x] += 1

def count(d, m, arr, cnt):
    b,s = 0, 0
    for x in arr:
        if x > m:
            b+=1
        else:
            s+=1
            
        if b-s in [0,1]:
            cnt[0]+=1
            
        push(d, b-s)    
    
index_m = -1     
for i,x in enumerate(p):
    if x == m:
        index_m = i
        break
        
cnt = [0]        
count(ld, m, p[:index_m][::-1],   cnt)
count(rd, m, p[index_m+1:], cnt)

for x, f in ld.items():
    if -x  in rd:
        cnt[0] += f * rd[-x]
        
    if 1-x in rd:
        cnt[0] += f * rd[1-x]
        
print(cnt[0]+1)      

#15 8
#1 15 2 14 3 13 4 8 12 5 11 6 10 7 9