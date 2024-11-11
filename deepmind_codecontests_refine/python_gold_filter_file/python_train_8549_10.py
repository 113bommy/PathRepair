z=[-1]*26;s=0;k=input().replace(""," ").split();j=len(k);i=0
while (i<j and j!=0):
    if z[ord(k[i])-97]==-1:z[-97+ord(k[i])]=i;i+=1
    else:
        if i-z[-97+ord(k[i])] ==1 :s+=1;r=k[i];k.pop(i);k.pop(z[-97+ord(r)]);z[-97+ord(r)]=-1;j-=2;i-=2
        else:z[-97+ord(k[i])]=i;i+=1
print("NYoe s"[s%2::2])