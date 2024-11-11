m=['a','e','i','o','u','A','E','I','O','U']
x=input()
i=x.index('?')-1
while x[i]==' ':
            i=i-1
            if x[i]!=' ':
                        break
if x[i] in m:
            print("YES")
else:
            print("NO")