number=int(input())
str1=input()
List=str1.split(' ')
for i in range(number):
    List[i]=int(List[i])
n1=List[0]%2
n2=List[1]%2
if n1!=n2:
    n3=List[2]%2
    if n3==n1:
        print(2)
    else:
        print(1)
else:
    for i in range(4,number):
        if List[i]!=n1:
            print(i+1)
        break