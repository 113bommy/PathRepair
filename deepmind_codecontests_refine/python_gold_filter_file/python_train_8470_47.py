#codeforces 166A
#@autor Yergali B
n=int(input())
a,b,c,d=0,0,0,0
for i in range(n+1,10001):
    a=i//1000
    b=i//100%10
    c=i//10%10
    d=i%10
    if a!=b and a!=c and a!=d and b!=c and b!=d and c!=d:
        print(i)
        break
