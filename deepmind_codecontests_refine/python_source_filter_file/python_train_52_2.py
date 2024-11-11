__author__ = 'Utena'
s=input().split()
n=int(s[-1])
add=0
minus=0
for a in s:
    if a=="+":add+=1
    if a=='-':minus+=1
if minus>n*add or add-n*minus>n:
    print('Impossible')
else:
    print("Possible")
    ans=[]
    if minus<add:
        q=add+minus
        q1=max(n-q,1)
        q-=n-q1
        ans.append(str(q1))
        for a in s:
            if a=='+':
                ans.append('+')
                ans.append('1')
            if a=='-':
                ans.append('-')
                q2=min(1+q,n)
                q-=q2-1
                ans.append(str(q2))
            if a=='=':
                ans.append('=')
                ans.append(str(n))
    else:
        ans.append(str(n))
        q=minus-add
        for a in s:
            if a=='+':
                ans.append('+')
                q3=max(n,1+q)
                q-=q3-1
                ans.append(str(q3))
            if a=='-':
                ans.append('-')
                ans.append('1')
            if a=='=':
                ans.append('=')
                ans.append(str(n))
    print(' '.join(ans))