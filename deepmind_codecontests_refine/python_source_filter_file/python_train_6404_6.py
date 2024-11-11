a=input()
b=input()
x=''

for i in range (len(a)):

    if a[i]==b[i]:
        x=x+'0'
    else:
        x=x+'1'
    
print(int(x))
