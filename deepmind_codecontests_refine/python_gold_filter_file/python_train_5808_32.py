n,a,b,c = map(int,input().split())
s = [input() for i in range(n)]+[0]
# if [a,b,c].count(0) >= 2:
#     print("No")
ans = ""

# print("Yes")
for i in range(n):
    if s[i] == "AB":
        if a==1 and b==1 and s[i+1] =="BC":
            ans+="B"
            b+=1
            a-=1
        elif a<=b:
            ans+="A"
            a+=1
            b-=1
        else:
            ans+="B"
            b+=1
            a-=1
    if s[i] == "AC":
        if a==1 and c==1 and s[i+1] =="BC":
            ans+="C"
            c+=1
            a-=1
        elif a<=c:
            ans+="A"
            a+=1
            c-=1
        else:
            ans+="C"
            c+=1
            a-=1       
    if s[i] == "BC":
        if b==1 and c==1 and s[i+1] =="AC":
            ans+="C"
            c+=1
            b-=1
        elif b<=c:
            ans+="B"
            b+=1
            c-=1
        else:
            ans+="C"
            c+=1
            b-=1   
    if a<0 or b<0 or c<0:
        print("No") 
        exit()
print("Yes")
for i in ans:
    print(i)   