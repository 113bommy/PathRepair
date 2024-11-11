chk = True
n = int(input())
st = input()
l = list(st)
s=0
if n == 1 and int(l[0]) == 0:
    chk = False

else :
    def test():
        for i in range(len(l)-1):
            if int(l[i]) + int(l[i+1]) > 1 :
                chk = False
                return False
        return True
    test()
    if chk:
        for i in range(len(l)):
            if int(l[i])==0:
                l[i] = '1'
                if test():
                    chk = False
                    break
                else:
                    l[i] = '0'
        
    

if(chk):
    print("Yes")
else:
    print("No")
        
    

