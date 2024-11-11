import _string
s=input()
s1=input()
s2=input()
hassan=''

index2=-1
for i in s2:

    if i=='0' or i=='1' or i=='2'or i=='3' or i=='4' or i=='5' or i=='6' or i=='7' or i=='8' or i=='9':
        hassan+=i
        continue
    if i.isupper():

        index1=s.index(i.lower())
        hassan+=(s1[index1]).upper()
        continue
    else:
        index1 = s.index(i.lower())
        hassan += (s1[index1]).upper()
        continue
print(hassan)