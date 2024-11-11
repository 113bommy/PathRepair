def bt(s):
    maxi=0
    for i in alphabet:
        k=s.count(i)
        if k>maxi:
            maxi=k
    return maxi
def maxbt(s,n):
    #за len(s)-bt(s) строка станет красивой
    #остается n-(len(s)-bt(s)) ходов. Если это четно, то maxbt=len(s)
    if n<=len(s)-bt(s):
        return n+bt(s)
    elif len(s)-bt(s)==0 and n==1:
        return len(s)
    else:
        return len(s)
alphabet=['A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z']
n=int(input())
s1=input()
s2=input()
s3=input()
k1=maxbt(s1,n)
k2=maxbt(s2,n)
k3=maxbt(s3,n)
d=max(k1,k2,k3)
if (k1==k2 and k1==d) or (k2==k3 and k2==d) or (k3==k1 and k1==d):
    print('Draw')
else:
    if k1==max(k1,k2,k3):
        print('Kuro')
    if k2==max(k1,k2,k3):
        print('Shiro')
    if k3==max(k1,k2,k3):
        print('Katie')
    
