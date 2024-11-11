t=int(input())
for q in range(0,t,1):
    n=int(input())
    a=input()
    m=0
    i=len(a)
    for j in range(0,len(a)):
        if a[j]=='A':
            i=j
            break
    for j in range(i,len(a),1):
        if 'A'==a[j]:
            m=max(m,j-i-1)
            i=j
    m=max(len(a)-i-1,m)
    print(m)
