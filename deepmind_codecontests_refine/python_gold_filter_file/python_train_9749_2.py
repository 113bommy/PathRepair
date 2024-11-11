def gcd(a,b):
    if b==0 :
        return a
    return gcd(b,a%b)
mas=[]
n = int(input())
i = 0
mase = input().split()
while i < n:
    mas.append(int(mase[i]))
    i+=1
mas.sort()
i = 0
raz=[]
while i < n-1:
    raz.append(int(mas[i+1])-int(mas[i]))
    i+=1
raz.sort()
a=raz[0]
i=0
while i < n-1:
    a=gcd(a,raz[i])
    i+=1
i=0
ans=0
while i < n-1:
    ans+=(raz[i])/a-1
    i+=1
print(int(ans))