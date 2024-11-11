n=int(input())
s=str(input())
ix=0
a=1
while ix<n:
    print(s[ix],end='')
    ix+=a
    a+=a
