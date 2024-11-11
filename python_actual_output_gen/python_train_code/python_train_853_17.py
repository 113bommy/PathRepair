n=int(input())
t=list(map(int, input()))
fi=sorted(t[:n])
se=sorted(t[n:])
#print(fi,se)
if fi[0] > se[0]:
    ch=1
    for i in range(n):
        if fi[i] < se[i]:
            ch=0
            print("NO")
            break
    if ch:
        print("YES")
    
elif fi[0] < se[0]:
    ch=1
    for i in range(n):
        if fi[i] > se[0]:
            
            ch=0
            print("NO")
    if ch:
        print("YES")
else:
    print("NO")