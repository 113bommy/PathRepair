k,a,b=map(int,input().split())
if b-a<=2 or k-1<a:
    print(1+k)
else:
    print((k-a+1)//2*(b-a)+(k-a+1)%2+a)