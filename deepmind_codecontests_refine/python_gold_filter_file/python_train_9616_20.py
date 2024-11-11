n=int(input())
l=list(map(int,input().split()))
e,o=0,0
e_i,o_i=0,0
for i in range(n):
    if l[i]%2==0:
        e+=1
        e_i=i
    if l[i]%2==1:
        o+=1
        o_i=i
    if  e>1 and o==1:
        print(o_i+1)
        break
    if o>1 and e==1:
        print(e_i+1)
        break