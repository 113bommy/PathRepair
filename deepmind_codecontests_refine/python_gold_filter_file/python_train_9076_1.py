for _ in range(int(input())):
    n=input()
    p=[]
    if len(n)==1:
        print(n)
        continue
    n+=" "
    i=0
    while i<len(n)-1:
        if n[i]!=n[i+1]:p.append(n[i])
        else:i+=1
        i+=1
    print(*sorted(set(p)),sep="")

# My code says who am i
# I want to burn and born at this way
# In my eye there is not any things Except love ...