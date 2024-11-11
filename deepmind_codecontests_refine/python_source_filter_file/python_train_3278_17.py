n = input()
if('0' in n):
    print("YES")
    print("0")
    exit(0)
if('8' in n):
    print("YES")
    print("8")    
    exit(0)
num = int(n)
x = int(num/8)

def SinN(s,n):
    i = 0
    for c in s:
        #print("Zoek:",c,"in",s[i:],"vanaf:",i)
        i = n.find(c,i)+1
        if(i==0):
            return False
        
    return True
while(x>0):
    
    for i in range(0,80,8):
        s = str(x*8 + i)
        #print(x,s)
        if(SinN(s,n)):
            print("YES")
            print(s)
            exit(0)
    x = int(x/10)
print("NO")
