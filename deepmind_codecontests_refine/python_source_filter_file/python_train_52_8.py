s=input()
n=int( (s.split(' = '))[1])
a=s.count('+')
b=s.count('-')
mx=(a+1)*n-b
mn=(a+1)-b*n
if mn<=n<=mx:
    print("Possible")
    need = n - b; ans = s[1:]
    while need < 1 or need > n:
        if need > n:
            ans = ans.replace("+ ?", "+ " + str(n), 1)
            need -= (n - 1)
        else:
            ans = ans.replace("- ?", "- " + str(n), 1)
            need += (n - 1)
    print(str(need) + ans.replace('?', '1'))
else:
    print ("Impossible")
