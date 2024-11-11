q =int(input())
j=0
lst = []
while(q>0):
    ans =""
    n =int(input())
    str = input()
    i=0
    if n==2:
        if int(str[1])>int(str[0]):
            ans = ans + str[0]
            ans += " "
            ans = ans + str[1]
        else:
            ans = ""
    else:
        ans = ans + str[0]
        ans += " "
        ans = ans + str[1:n]
    lst.append(ans)
    q -= 1
for ele in lst:
    if ele!="":
        print("Yes")
        print(2)
        print(ele)
    else:
        print("No")
    