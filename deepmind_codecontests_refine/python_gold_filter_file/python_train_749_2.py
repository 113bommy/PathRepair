s=')'+input()+'('
i,j=0,1002
a=[]
while i<j:a+=i,j;i=s.find('(',i+1);j=s.rfind(')',0,j)
a=a[2:]
print(0+(a>[]),*a and[len(a)]+sorted(a))