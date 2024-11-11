h=input()
t=h.split()
if int(t[0]) % int(t[2])==0:
    k1=int(t[0])//int(t[2])
else:
    k1=(int(t[0])//int(t[2]))+1
if (int(t[1]) % int(t[2]))==0:
    k2=int(t[1])//int(t[2])
else:
    k2=(int(t[1])//int(t[2]))+1
print(k1+k2)