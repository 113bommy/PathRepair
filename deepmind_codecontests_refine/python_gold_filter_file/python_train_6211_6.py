from collections import defaultdict

m = int(input())
value = {}
count = defaultdict(int)

for i in range(m):
    s = input()
    ans = 0
    z = ""
    n = len(s)
    for j in range(1,n):
        if s[j]=='+':
            ans = int(z)
            z = ""
            continue
        elif s[j]==')':
            ans +=int(z)
            z = ""
            j+=2
            while j<n:
                z+=s[j]
                j+=1
            ans = ans/int(z)
            count[ans]+=1
            value[i] = ans
        else:
            z = z+s[j]

for i in range(m):
    print(count[value[i]],end=" ")
print()
