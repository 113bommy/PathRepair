n,s=open(0);a=i=j=0
while j<3e7:f=s[i:j]in s[j:];a=max(a,j*f-i);j+=f;i+=f^1
print(a)