### Almost Equal ###
### https://codeforces.com/contest/1205/problem/A ###
n=int(input())
a=[1]*n*2
b=" "
if n%2==0:
    print("NO")
elif n%2==1:
    print("YES")
    for i in range(0,n):
        if i%2==0:
            a[i]=str(2*i+1)
        elif i%2==1:
            a[i]=str(2*i+2)
        j=n+i
        if i%2==0:
            a[j]=str(2*(i)+2)
        elif i%2==1:
            a[j]=str(2*(i)+1)
    print(b.join(a))
