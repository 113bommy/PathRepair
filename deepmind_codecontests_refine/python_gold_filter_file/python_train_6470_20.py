n=int(input())
st=input()
z=(n-11)//2
ct=0
for j in range(n-10):
    if(st[j]=="8"):
        ct+=1
if(ct>=(z+1)):
    print("YES")
else:
    print("NO")