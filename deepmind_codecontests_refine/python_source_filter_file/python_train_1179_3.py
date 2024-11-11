# http://codeforces.com/problemset/problem/171/A
a,b=input().split()
n=max(len(a),len(b))
a=('0'*n+a)[-n:]
b=('0'*n+b)[-n:]
ans=[]
carry=0
for j,i in  zip(b,reversed(a)):
    x=int(i)+int(j)+carry
    carry=x//10
    ans.append(str(x%10))
ans.append(str(carry))
print(int(''.join(reversed(ans))))
