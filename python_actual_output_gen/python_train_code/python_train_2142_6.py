n, m= input().split()
log=n[0]
for i in range(1,len(n)-1):
    if n[i]<m[0]:
        log+=n[i]
    else: break
log+=m[0]
print(log)