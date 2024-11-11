t=int(input())
for j in range(t):
    n=int(input())
    for i in range(1,500):
        if(((i-2)*180//i)==n):
            c="YES"
            break
        else:
            c="NO"
    
    print(c)