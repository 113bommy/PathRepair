n=int(input(''))
result=0
while n>0:
    n-=1
    z=input()
    if z=='++X' or z=='X++':
        result+=1
    else:
        result-+1
print(result)