def Bina(n):
    s=""
    while n!=0:
        s+=str(n%2)
        n= n//2
    return s
            
def Zeros(b):
    ones=0
    for i in range(b.__len__()):
        if("1"==b[i]):
            ones+=1
    return 6-ones

total=1
alphabet= list(
        '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-')
dic = {}
num=0
for i in alphabet:
    dic[i]= Zeros(Bina(alphabet.index(i)) ) 

M=int(1e9+7)   
for i in input():
     if(i=="_"): continue
     num = dic[i]
     total*= (3**num )%M

print(total)



