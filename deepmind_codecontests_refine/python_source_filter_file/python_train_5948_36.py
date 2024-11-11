t=int(input())
s=input()
h=list(map(str, s))
j=1
k=0
while k<t:
    print(h[k],end="")
    k=k+j
    j=j+j