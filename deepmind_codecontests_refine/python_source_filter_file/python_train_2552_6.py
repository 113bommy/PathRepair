n=int(input())
nombres=[]
rec=0
tot=0
nbr=input()
nbr=nbr.split(" ")
for x in range(0,n):
 a=int(nbr[x])
 if a in nombres and a!=0:
  rec+=1
 tot+=a
 nombres.append(a)
print(tot-rec)