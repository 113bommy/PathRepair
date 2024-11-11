#n=int(input())
s=input()
"""r,t=min((sum(x!=y for x,y in zip(s,t*n)),t)for t
        in('RGB','RBG','GRB','GBR','BRG','BGR'))
print(r,(t*n)[:n])"""
j,k=1,0
for i in s:
        if i=='1':print(1,j%4);j+=2
        else: print(3,1+ k%4);k+=1
