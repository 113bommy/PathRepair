### https://codeforces.com/problemset/problem/32/B
a = input()
a=list(a)
#print(a)
n=len(a)
out=[]
i=0
while i<n:
    if a[i]=='.':
        out.append(0)
        i=i+1
    elif (a[i]=='-') & (a[i+1]=='.'):
        out.append(1)
        i=i+2
    else:
        out.append(2)
        i=i+2
        
for num in out:
    print(num, end='')