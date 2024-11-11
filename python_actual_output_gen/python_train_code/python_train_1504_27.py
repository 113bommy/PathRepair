n=int(input())  #96
a=""
while n>0:
    n-=1
    rem=n%26
    a+=chr(97+rem)
    n=(n-rem)//26
    
print(a)


