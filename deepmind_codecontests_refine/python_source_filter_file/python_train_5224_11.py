# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
a=input()
b=["0"]*10
for i in a:
    if i=='L':
        for j in range(10):
            if b[j]=='0':
                b[j]='1'
                # print(*b,sep="")    
                break
    elif i=='R':
        for j in range(9,-1):
            if b[j]=='0':
                b[j]='1'
                # print(*b,sep="")
                break
    else:
        b[int(i)]='0'
        # print(*b,sep="")
print(*b,sep="")        
                                