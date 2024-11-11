def fabio(i):
    if i==1 :
        return 1
    elif i==2 :
        return 1
    else :
        return fabio(i-2) + fabio(i-1)
n=int(input())
t=[]
for i in range(n):
    t.append(fabio(i+1))
    if fabio(i+1) > n :
        break
ch=""
for i in range(n) :
    if i+1 in t :
        ch+='O'
    else :
        ch+='o'
        
print(ch)
