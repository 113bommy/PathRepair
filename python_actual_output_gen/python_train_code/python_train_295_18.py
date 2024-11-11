n=int(input())
s={ 1:'a',2:'b',3:'c',4:'d'}
s1=''
for i in range(1,n+1):
    if i%4!=0:
        z=i%4
        s1=s1+s[z]
    else:
        z=i/4
        s1=s1+s[z]
print(s1)        