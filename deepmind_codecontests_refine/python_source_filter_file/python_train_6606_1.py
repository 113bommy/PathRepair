

def combination(m , n):
    a=1
    for i in range(n):
        a*=(m-i)
    for i in range(1,n+1):
        a/=i
    return a


command=input()
recognize=input()

command=[i for i in command]
recognize=[i for i in recognize]

comPostive=0
comNegative=0

recPostive=0
recNegative=0
for i in command:
    if(i=='+'):
        comPostive+=1
    if(i=='-'):
        comNegative+=1

for i in recognize:
    if(i=='+'):
        recPostive+=1
    if(i=='-'):
        recNegative+=1

postive=comPostive-recPostive
negative=comNegative-recNegative
# print(postive)
# print(negative)
if(postive==0 and negative==0):
    print(float(1))
elif(postive>0 and negative>0):
    a=combination(postive+negative,postive)
    b=2**(postive+negative)
    print(a/b)
else:
    print(float(0))
