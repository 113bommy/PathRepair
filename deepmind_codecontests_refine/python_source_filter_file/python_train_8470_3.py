def check(n):
    r1=n%10
    n=n//10
    r2=n%10
    n=n//10
    r3=n%10
    r4=n//10
    if(r1!=r2 and r1!=r3 and r2!=r3 and r1!=r4 and r2!=r4 and r3!=r4):
        return False
    else:
        return True
        
s=input()
n=int(s)
a=list(s)
while(check(n)):
    n=n+1
print(n)