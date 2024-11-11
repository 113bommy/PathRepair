
# Online Python - IDE, Editor, Compiler, Interpreter
def prime(n):
    i = 2
    while(i*i<=n):
        if(n%i==0):
            return False
        i+=1
    return True

for _ in range(int(input())):
    k = int(input())
    s = input()
    t = {'4', '6', '8', '9', '1'}
    flg = 0
    for i in s:
        if i in t:
            flg=1
            print(1)
            print(i)
            break
    if(flg==1):
        continue
    for i in range(k):
        for j in range(i+1, k):
            if(not prime(int(s[i]+s[j]))):
                print(2)
                print(s[i]+s[j])
                flg=1
                break
        if(flg==1):
            break
    if(flg==0):
        print(k)
        print(s)
    