s=input().strip()
n=len(s)
for i in s:
    if s.count(i)>=n-1:

        print('Impossible')
        break
else:


    for i in range(n//2):
        p=s[i+1:]+s[:i+1]
        #print(p)
        if p==p[::-1]:
            print(1)
            break
    else:

        print(2)