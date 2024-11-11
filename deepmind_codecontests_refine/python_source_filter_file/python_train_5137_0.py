# cook your dish here
def Divisors(a,l1,l2) : 
    i = 1
    while i <= min(l1,l2) : 
        if (l1 % i==0 and l2 % i==0) : 
            a.append(i)
        i = i + 1
        
s1=input()
s2=input()
l1, l2 = len(s1), len(s2)
a=[]
Divisors(a,l1,l2)
ss1, ss2, c = "", "", 0
for i in range(len(a)):
    ss1=s1[:a[i]]*(l1//a[i])
    ss2=s2[:a[i]]*(l2//a[i])
    if ss1==s1 and ss2==s2:
        c+=1
print(c)        