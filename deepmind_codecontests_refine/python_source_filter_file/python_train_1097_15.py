a=b=c=0
for _ in range(int(input())):
    a,b,c=[int(i) for i  in input().split()]
    a+=a
    b+=b
    c+=c
if a==0 and b==0 and c==0:
    print("YES")
else:
    print("NO")
