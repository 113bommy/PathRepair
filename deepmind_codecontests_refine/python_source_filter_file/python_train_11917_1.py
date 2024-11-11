n=int(input())
a=0
b=0
c=0
for i in range(n):
        c=i+1
        s=int((c*(c+1))/2)
        # print(s)
        a+=s
        if a<=n:
            print(a)
            b=i+1
            print(b)
        else:
            break
print(b)
